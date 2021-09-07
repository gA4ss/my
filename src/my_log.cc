#include <my_log.h>
#include <my_common.h>

#ifdef OS_LINUX
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#endif

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <string>

namespace my {

static int g_debug_level = MYLOG_LEVEL_NONE;
static int g_debug_type = MYLOG_TYPE_STDOUT;
static std::string g_log_file_path = "";
static FILE* g_output_handle = nullptr;
static bool g_logger_runnning = false;

static void _log_on_level(int curr_level, const char* buf) {
  const char* prefix = nullptr;

  if (curr_level == MYLOG_LEVEL_WARNING) prefix = "[warning]";
  else if (curr_level == MYLOG_LEVEL_ERROR) prefix = "[error]";
  else if (curr_level == MYLOG_LEVEL_FATAL) prefix = "[fatal]";
  else if (curr_level == MYLOG_LEVEL_DEBUG) prefix = "[debug]";
  else prefix = ""; 

  if (curr_level <= g_debug_level) {
    if (g_debug_type == MYLOG_TYPE_FILE) {
      fprintf(g_output_handle, "%s%s", prefix, buf);
    } else if (g_debug_type == MYLOG_TYPE_BOTH) {
      fprintf(g_output_handle, "%s%s", prefix, buf);
      printf("%s%s", prefix, buf);
    } else if (g_debug_type == MYLOG_TYPE_STDOUT) {
      printf("%s%s", prefix, buf);
    } else {
      // ...
    }
  }
}

int logger(int curr_level, const char* filepath, 
           int lineno, const char* funcname, 
           const char* fmt, ...) {
  int ret = 0;
  va_list args;
  char buffer[2048] = {0};

  if (!g_logger_runnning) return -1;

  //
  // FIXME : 没校验缓存长度,可能存在溢出
  //
  va_start(args, fmt);
  vsprintf(buffer, fmt, args);
  va_end(args);

  std::string title = "";
  if (filepath) {
    std::string filename = filepath;
    filename = filename.substr(filename.find_last_of('/')+1);
    title += filename;
    title += ":";
    title += std::to_string(lineno);
    title += ":";
  }
  if (funcname) {
    title += funcname;
    title += ": ";
  }
  title += buffer;

  _log_on_level(curr_level, title.c_str());
  return ret;
}

static void _logger_get_filepath(const char* path=nullptr) {
  //
  // FIXME : 这里没有对buffer进行验证
  //
  char logfile[1024] = {0};
  time_t timep;
  time (&timep);
  if (path) {
    strftime(logfile, 1024, "%Y_%m_%d_%H_%M_%S.log", localtime(&timep));
    g_log_file_path = path;
    if (*(g_log_file_path.end()-1) == '/') {
      g_log_file_path += logfile;
    } else {
      g_log_file_path += (std::string("/") + logfile);
    }
  } else {
    strftime(logfile, 1024, "./%Y_%m_%d_%H_%M_%S.log", localtime(&timep));
    g_log_file_path = logfile;
  }
  g_log_file_path = get_real_path(g_log_file_path);
  //printf("%s\r\n",g_log_file_path.c_str());
}

static void _logger_close(bool e) {
  if (!g_logger_runnning) return;
  if (g_debug_type>= MYLOG_TYPE_FILE) {
    if (g_output_handle) {
      fflush(g_output_handle);
      fclose(g_output_handle);
      g_output_handle = nullptr;
    }
  }
  g_logger_runnning = false;
  //printf("_logger_close\r\n");
  if (e) exit(-1);
}

static void _logger_on_signal(int signo) {
  _logger_close(true);
}

static void _logger_on_exit(void) {
  _logger_close(false);
}

int init_logger(int level, int type, const char* log_path, bool nosign) {
  if (g_logger_runnning) return 1;

  g_logger_runnning = true;
  if (level < MYLOG_LEVEL_NONE) level = MYLOG_LEVEL_NONE;
  if (level > MYLOG_LEVEL_DEBUG) level = MYLOG_LEVEL_DEBUG;
  g_debug_level = level;

  if (type < MYLOG_TYPE_STDOUT) type = MYLOG_TYPE_STDOUT;
  if (type > MYLOG_TYPE_BOTH) type = MYLOG_TYPE_BOTH;
  g_debug_type = type;

  if (type > MYLOG_TYPE_STDOUT) {
    // 自动生成一个日志文件名
    _logger_get_filepath(log_path);
    g_output_handle = fopen(g_log_file_path.c_str(), "w");
    if (!g_output_handle) {
      // FIXME : 打开文件出错的一些处理
      g_output_handle = nullptr;
      g_log_file_path = "";
      g_debug_type = MYLOG_TYPE_STDOUT;
    }
  }

  //
  // 注册信号函数
  //
  if (!nosign) {
    atexit(_logger_on_exit);
    signal(SIGTERM, _logger_on_signal);
    signal(SIGINT, _logger_on_signal);
  }
  return 0;
}

void shutdown_logger(bool e) {
  _logger_close(e);
}

} // namesapce my