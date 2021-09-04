#ifndef MY_MY_OBJECT_H_
#define MY_MY_OBJECT_H_

#include <my/my_common.h>

namespace my {

#define kMyObjectId               0

class Object {
public:
  Object() : id_(uuid()) {}
  virtual ~Object() {}

  std::string id() { return id_; }
  std::string id() const { return id_; }

  virtual const int class_type() { return kMyObjectId; }
  virtual const int class_type() const { return kMyObjectId; }
  virtual const char* class_name() { return "object"; }
  virtual const char* class_name() const { return "object"; }

protected:
  std::string id_;
};

} // namespace my

#endif // MY_MY_OBJECT_H_