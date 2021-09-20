#ifndef MY_MY_OBJECT_H_
#define MY_MY_OBJECT_H_

#include <my/my_common.h>

namespace my {

#define kMyObjectID               0

class Object {
public:
  Object() : id_(uuid()) {}
  virtual ~Object() {}

  std::string id() const { return id_; }
  virtual const int class_type() const { return kMyObjectID; }
  virtual const char* class_name() const { return "object"; }

protected:
  std::string id_;
};

typedef std::shared_ptr<Object> my_object_t;
typedef std::vector<my_object_t> my_objects_t;

template<typename T>
std::shared_ptr<Object> create_object() {
  //
  // FIXME : 校验传入模板类型
  //
  return std::make_shared<T>();
}

template<typename T>
std::shared_ptr<T> dyn_cast(std::shared_ptr<Object> ptr) {
  return std::dynamic_pointer_cast<T>(ptr);
}

// template<typename T>
// std::shared_ptr<
//   typename std::enable_if<!std::is_same<Object, T>::value)
//                           &&(std::is_base_of<Object, T>::value), T>::type>
// dyn_cast(std::shared_ptr<Object> ptr) {
//   return std::dynamic_pointer_cast<T>(ptr);
// }

} // namespace my

#endif // MY_MY_OBJECT_H_