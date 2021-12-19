#ifndef MY_MY_TYPE_HPP_
#define MY_MY_TYPE_HPP_

#include <string>
#include <utility>
#include <cxxabi.h>
#include <typeinfo>

namespace my {

typedef enum {
  kUnknownT = 0,
  kCharT = 1,
  kUCharT = 2,
  kShortT = 3,
  kUShortT = 4,
  kIntT = 5,
  kUIntT = 6,
  kLongT = 7,
  kULongT = 8,
  kLongLongT = 9,
  kULongLongT = 10,
  kFloatT = 11,
  kDoubleT = 12,
  kLDoubleT = 13,
  kBIntegerT = 14,
  kBFloatT = 15
} support_type_t;

const std::string class_name(const char * name) {
  int status = -1;
  char* clear_name = abi::__cxa_demangle(name, NULL, NULL, &status);
  const char * const  demangled_name = (status == 0) ? clear_name : name;
  std::string ret_val(demangled_name);
  free(clear_name);
  return ret_val;
}

template <class T>
std::string get_type_name() {
  return typeid(T).name();
}

template <class T>
support_type_t get_support_type() {
  support_type_t r = kUnknownT;
  std::string tn = get_type_name<T>();
  if (tn == "c") {
    r = kCharT;
  } else if (tn == "h") {
    r = kUCharT;
  } else if (tn == "s") {
    r = kShortT;
  } else if (tn == "t") {
    r = kUShortT;
  } else if (tn == "i") {
    r = kIntT;
  } else if (tn == "j") {
    r = kUIntT;
  } else if (tn == "l") {
    r = kLongT;
  } else if (tn == "m") {
    r = kULongT;
  } else if (tn == "x") {
    r = kLongLongT;
  } else if (tn == "y") {
    r = kULongLongT;
  } else if (tn == "f") {
    r = kFloatT;
  } else if (tn == "d") {
    r = kDoubleT;
  } else if (tn == "e") {
    r = kLDoubleT;
  } else if (tn == "Integer") {
    r = kBIntegerT;
  } else if (tn == "Float") {
    r = kBFloatT;
  } else {
    r = kUnknownT;
  }
  return r;
}

} // namespace my

#endif // MY_MY_TYPE_HPP_