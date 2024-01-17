#ifndef MY_MY_EXCEPTION_H_
#define MY_MY_EXCEPTION_H_

#include <string>
#include <exception>
#include <functional>
#include <vector>
#include <my/my_object.h>

namespace my
{

  class MyExceptObject : public MyObject
  {
  public:
    MyExceptObject();
    virtual ~MyExceptObject();
  };

  typedef MyExceptObject except_object_t;
  typedef except_object_t *except_object_ptr_t;
  typedef std::vector<except_object_ptr_t> except_object_ptrs_t;

  //////////////////////////////////////////////////////////////////////

  class MyException : public std::exception
  {
  public:
    MyException();
    MyException(const char *type,
                const char *filepath, int lineno, const char *funcname,
                except_object_ptrs_t except_object_ptrs,
                const char *fmt, ...);
    virtual const char *what() const throw();
    virtual std::string type() const;
    except_object_ptr_t objects(size_t i);

    static std::string __make_info_prefix(const char *filepath, int lineno, const char *funcname);

  protected:
    std::string info_;
    std::string type_;
    except_object_ptrs_t except_object_ptrs_;
  };

  typedef std::function<void(MyException &)> exception_handle_t;
  bool register_exception_function(std::string type, exception_handle_t func);
  bool exception_function_call(MyException &e);

} // namespace my

#define MYSTART try
#define MYEND                       \
  catch (my::MyException &e)  \
  {                                 \
    my::exception_function_call(e); \
  }

#endif // MY_MY_EXCEPTION_H_