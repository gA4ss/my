#ifndef MY_MY_OBJECT_H_
#define MY_MY_OBJECT_H_

#include <my/my_common.h>

namespace my {

class Object {
public:
  Object() : id_(uuid()) {}
  virtual ~Object() {}

  std::string id() { return id_; }
  std::string id() const { return id_; }

  // virtual const char* type_name() { return "my_object"; }
  // virtual int type() { return 0; }

protected:
  std::string id_;
};

} // namespace my

#endif // MY_MY_OBJECT_H_