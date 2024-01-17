#ifndef MY_MY_LOG_H_
#define MY_MY_LOG_H_

#include <cstdio>
#include <cassert>

namespace my
{

//
// DEBUG LEVEL
//
#define MYLOG_LEVEL_NONE 0
#define MYLOG_LEVEL_INFO 1
#define MYLOG_LEVEL_WARNING 2
#define MYLOG_LEVEL_ERROR 3
#define MYLOG_LEVEL_FATAL 4
#define MYLOG_LEVEL_DEBUG 5

//
// DEBUG OUTPUT TYPE
//
#define MYLOG_TYPE_STDOUT 0
#define MYLOG_TYPE_FILE 1
#define MYLOG_TYPE_BOTH 2

  int init_logger(int level = MYLOG_LEVEL_NONE, int type = MYLOG_TYPE_STDOUT, const char *log_path = nullptr, bool nosign = false);
  void shutdown_logger(bool e = false);
  int logger(int curr_level, const char *filepath, int lineno, const char *funcname, const char *fmt, ...);

#define log_info(format, ...) logger(MYLOG_LEVEL_INFO, nullptr, 0, nullptr, format, __VA_ARGS__)
#define log_warning(format, ...) logger(MYLOG_LEVEL_WARNING, nullptr, 0, nullptr, format, __VA_ARGS__)
#define log_error(format, ...) logger(MYLOG_LEVEL_ERROR, nullptr, 0, nullptr, format, __VA_ARGS__)
#define log_fatal(format, ...) logger(MYLOG_LEVEL_FATAL, nullptr, 0, nullptr, format, __VA_ARGS__)
#define log_except(format, ...) logger(MYLOG_LEVEL_FATAL, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__)
#define log_debug(format, ...) logger(MYLOG_LEVEL_DEBUG, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__)
#define log_sign() logger(MYLOG_LEVEL_DEBUG, nullptr, 0, nullptr, "%s:%d:%s\r\n", __FILE__, __LINE__, __FUNCTION__)

#define log_assert(exp, format, ...)                                                  \
  {                                                                                   \
    logger(MYLOG_LEVEL_DEBUG, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
    assert((exp));                                                                    \
  }

} // namespace my

#endif // MY_MY_LOG_H_