#include <my/my_exception.h>

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

namespace my {

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
std::string MyException::__make_info_prefix(const char* filepath, 
                                            int lineno, 
                                            const char* funcname) {
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
  return title;
}

MyException::MyException() {
  info_ = "[my] ";
}
const char * MyException::what () const throw () {
  return info_.c_str();
}

InvalidArgumentsException::InvalidArgumentsException(const char* filepath, int lineno, const char* funcname) {
  info_ += __make_info_prefix(filepath, lineno, funcname);
  info_ += "Invalid arguments.";
}

OutOfRangeException::OutOfRangeException(const char* filepath, int lineno, const char* funcname) {
  info_ += __make_info_prefix(filepath, lineno, funcname);
  info_ += "Out of range.";
}

ExecuteErrorException::ExecuteErrorException(const char* context, int errcode, 
                                             const char* filepath, int lineno, const char* funcname) {
  info_ += __make_info_prefix(filepath, lineno, funcname);
  std::string s = std::string("Function execute \'") + 
                  std::string(context) + std::string("\' return : \'") +
                  std::to_string(errcode);
                  std::string("\'.");
  info_ += s;
}

InternalExecuteException::InternalExecuteException(const char* context,
                                                   const char* filepath, int lineno, const char* funcname) {
  info_ += __make_info_prefix(filepath, lineno, funcname);
  std::string s = std::string("Internal execute \'") + std::string(context) + std::string("\' exception.");
  info_ += s;
}

AssertException::AssertException(const char* filepath, int lineno, const char* funcname, const char* fmt, ...) {
  va_list args;
  char buffer[2048] = {0};
  //
  // FIXME : 没校验缓存长度,可能存在溢出
  //
  va_start(args, fmt);
  vsprintf(buffer, fmt, args);
  va_end(args);

  info_ += __make_info_prefix(filepath, lineno, funcname);
  info_ += buffer;
}

} // namespace my