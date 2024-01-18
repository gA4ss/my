#include <my/my_exception.h>
#include <my/my_log.h>

#include <map>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

namespace my
{

  MyExceptObject::MyExceptObject()
  {
  }

  MyExceptObject::~MyExceptObject()
  {
  }

  /* C++ 标准异常
   * std::bad_alloc	          该异常可以通过 new 抛出。
   * std::bad_cast	          该异常可以通过 dynamic_cast 抛出。
   * std::bad_exception	      这在处理 C++ 程序中无法预期的异常时非常有用。
   * std::bad_typeid	        该异常可以通过 typeid 抛出。
   * std::logic_error	        理论上可以通过读取代码来检测到的异常。
   * std::domain_error	      当使用了一个无效的数学域时，会抛出该异常。
   * std::invalid_argument	  当使用了无效的参数时，会抛出该异常。
   * std::length_error	      当创建了太长的 std::string 时，会抛出该异常。
   * std::out_of_range	      该异常可以通过方法抛出，例如 std::vector 和
   *                          std::bitset<>::operator[]()。
   * std::runtime_error	      理论上不可以通过读取代码来检测到的异常。
   * std::overflow_error	    当发生数学上溢时，会抛出该异常。
   * std::range_error	        当尝试存储超出范围的值时，会抛出该异常。
   * std::underflow_error	    当发生数学下溢时，会抛出该异常。
   */
  std::string MyException::__make_info_prefix(const char *filepath,
                                              int lineno,
                                              const char *funcname)
  {
    std::string title = "";
    if (filepath)
    {
      std::string filename = filepath;
      filename = filename.substr(filename.find_last_of('/') + 1);
      title += filename;
      title += ":";
      title += std::to_string(lineno);
      title += ":";
    }
    if (funcname)
    {
      title += funcname;
      title += ": ";
    }
    return title;
  }

  //
  // 异常处理变量
  //
  static std::map<std::string, exception_handle_t> __exception_handles;
  bool register_exception_function(std::string type, exception_handle_t func)
  {
    if (__exception_handles.find(type) == __exception_handles.end())
    {
      __exception_handles[type] = func;
      return true;
    }
    return false;
  }
  bool exception_function_call(MyException &e)
  {
    if (__exception_handles.find(e.type()) != __exception_handles.end())
    {
      __exception_handles[e.type()](e);
      return true;
    }
    return false;
  }

  MyException::MyException() {}
  MyException::MyException(const char *type,
                           const char *filepath, int lineno, const char *funcname,
                           const char *fmt, ...)
  {
    va_list args;
    char buffer[2048] = {0};
    //
    // FIXME : 没校验缓存长度,可能存在溢出
    //
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    type_ = type;
    info_ += __make_info_prefix(filepath, lineno, funcname);
    info_ += "[";
    info_ += type_;
    info_ += "]";
    // info_ += " Exception]";
    info_ += " \"";
    info_ += buffer;
    info_ += "\"";

    //
    // 记录到日志
    //
    logger(MYLOG_LEVEL_FATAL, nullptr, 0, nullptr, "%s", info_.c_str());
  }
  MyException::MyException(const char *type,
                           const char *filepath, int lineno, const char *funcname,
                           except_object_ptrs_t except_object_ptrs,
                           const char *fmt, ...)
  {
    va_list args;
    char buffer[2048] = {0};
    //
    // FIXME : 没校验缓存长度,可能存在溢出
    //
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    type_ = type;
    info_ += __make_info_prefix(filepath, lineno, funcname);
    info_ += "[";
    info_ += type_;
    info_ += "]";
    // info_ += " Exception]";
    info_ += " \"";
    info_ += buffer;
    info_ += "\"";

    //
    // 记录到日志
    //
    logger(MYLOG_LEVEL_FATAL, nullptr, 0, nullptr, "%s", info_.c_str());

    //
    // 记录异常对象
    //
    except_object_ptrs_ = except_object_ptrs;
  }

  const char *MyException::what() const throw()
  {
    return info_.c_str();
  }

  std::string MyException::type() const
  {
    return type_;
  }

  except_object_ptr_t MyException::objects(size_t i)
  {
    if (except_object_ptrs_.size() > i)
      return except_object_ptrs_[i];
    return nullptr;
  }

} // namespace my