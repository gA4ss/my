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

//////////////////////////////
//        内部变量定义        //
//////////////////////////////
typedef std::pair<std::string, Object*> variable_t;

} // namespace my

#endif // MY_MY_TYPE_H_