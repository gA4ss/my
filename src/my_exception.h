#ifndef MY_MY_EXCEPTION_H_
#define MY_MY_EXCEPTION_H_

#include <string>
#include <exception>

namespace my {

class MyException : public std::exception {
public:
  MyException();
  virtual const char * what () const throw ();

  static std::string __make_info_prefix(const char* filepath, int lineno, const char* funcname);
protected:
  std::string info_;
};

class InvalidArgumentsException : public MyException {
public:
  InvalidArgumentsException(const char* filepath, int lineno, const char* funcname);
};

class OutOfRangeException : public MyException {
public:
  OutOfRangeException(const char* filepath, int lineno, const char* funcname);
};

class AssertException : public MyException {
public:
  AssertException(const char* filepath, int lineno, const char* funcname, const char* fmt, ...);
};

//////////////////////////////////////////////////////////////////////

} // namespace my

#endif // MY_MY_EXCEPTION_H_