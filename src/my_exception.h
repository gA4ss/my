#ifndef MY_MY_EXCEPTION_H_
#define MY_MY_EXCEPTION_H_

#include <string>
#include <exception>

namespace my {

class MyException : public std::exception {
public:
  MyException();
  MyException(const char* type, 
              const char* filepath, int lineno, const char* funcname, 
              const char* fmt, ...);
  virtual const char * what () const throw ();
  virtual const char * type () const;

  static std::string __make_info_prefix(const char* filepath, int lineno, const char* funcname);
protected:
  std::string info_;
  std::string type_;
};

//////////////////////////////////////////////////////////////////////

} // namespace my

#endif // MY_MY_EXCEPTION_H_