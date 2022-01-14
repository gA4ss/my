#ifndef MY_MY_TYPE_HPP_
#define MY_MY_TYPE_HPP_

#include <string>
#include <utility>
#include <cxxabi.h>
#include <typeinfo>

namespace my {

typedef enum {
  kCharT = 0,
  kUCharT = 1,
  kShortT = 2,
  kUShortT = 3,
  kIntT = 4,
  kUIntT = 5,
  kLongT = 6,
  kULongT = 7,
  kLongLongT = 8,
  kULongLongT = 9,
  kFloatT = 10,
  kDoubleT = 11,
  kLDoubleT = 12,
  kStdTypeNumber = 13,
  KPointCharT = 13,
  KCPointCharT = 14,
  KStringT = 15,
  kBIntegerT = 16,
  kBFloatT = 17,
  kUnknownT = 18,
  kTypeNumber = 19
} support_type_t;

template <class T>
std::string get_type_name() {
  return typeid(T).name();
}

template <class T>
support_type_t get_support_type() {
  support_type_t r = kUnknownT;
  std::string tn = get_type_name<T>();
  if (tn.find("string") != std::string::npos) {
    r = KStringT;
  } else if (tn == "Pc") {
    r = KPointCharT;
  } else if (tn == "PKc") {
    r = KCPointCharT;
  } else if (tn == "c") {
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
  } else if (tn == "N5mynum7IntegerE") {
    r = kBIntegerT;
  } else if (tn == "N5mynum5FloatE") {
    r = kBFloatT;
  } else {
    r = kUnknownT;
  }
  return r;
}

template <class T>
bool __is_big_integer_type() {
  return (get_support_type<T>() == kBIntegerT);
}

template <class T>
bool __is_big_float_type() {
  return (get_support_type<T>() == kBFloatT);
}

} // namespace my

#endif // MY_MY_TYPE_HPP_