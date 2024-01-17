#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <my/my_common.h>
#include <my/my_exception.h>

using namespace std; 

class TestObject : public my::except_object_t
{
public:
  int v;

public:
  TestObject()
  {
    v = 0;
  }

  virtual ~TestObject()
  {
  }
};

void foo_exp(my::MyException &exp)
{
  std::cout << exp.what() << "  in foo_exp" << std::endl;
  my::except_object_ptr_t obj1, obj2;
  obj1 = exp.objects(0);
  obj2 = exp.objects(1);
  TestObject* tobj1 = dynamic_cast<TestObject*>(obj1);
  TestObject* tobj2 = dynamic_cast<TestObject*>(obj2);
  std::cout << tobj1->v << " " << tobj2->v << std::endl;
}

void happen_exception(TestObject &obj1, TestObject &obj2)
{
  throw my::MyException("test", __FILE__, __LINE__, __FUNCTION__, {&obj1, &obj2}, "%s", "hello world");
}

int main(int argc, char *argv[])
{
  my::register_exception_function("test", foo_exp);

  TestObject obj1, obj2;
  obj1.v = 1;
  obj2.v = 2;

  MYSTART
  {
    happen_exception(obj1, obj2);
  }
  MYEND
  return 0;
}