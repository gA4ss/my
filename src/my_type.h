#ifndef MY_MY_TYPE_H_
#define MY_MY_TYPE_H_

#include <my/my_object.h>

namespace my {

//////////////////////////////
//        内部函数指针       //
/////////////////////////////
typedef std::vector<Object*> params_t;
typedef std::vector<Object*> returns_t;
typedef returns_t (*function_t)(const params_t&);

void init_my_type_system();
int registry_type(const char* tname);
int query_type(const char* tname);
const char* query_type(int tid);

} // namespace my

#endif // MY_MY_TYPE_H_