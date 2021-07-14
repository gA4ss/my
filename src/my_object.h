#ifndef MY_MY_OBJECT_H_
#define MY_MY_OBJECT_H_

#include <my/my_common.h>

namespace my {

enum {
  kPrintStyleNormal = 0,
  kPrintSytleLatex = 1
};

class Object {
public:
  Object() : print_style_(kPrintStyleNormal), id_(uuid()) {}
  virtual ~Object() {}

  virtual std::string str() { return ""; }
  virtual std::string str() const { return ""; }

  void set_print_style(int ps=kPrintStyleNormal) { print_style_ = ps; }

  int get_print_style() { return print_style_; }
  int get_print_style() const { return print_style_; }

  std::string id() { return id_; }
  std::string id() const { return id_; }

protected:
  int print_style_;
  std::string id_;
};

} // namespace my

#endif // MY_MY_OBJECT_H_