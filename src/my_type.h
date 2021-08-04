#ifndef MY_MY_TYPE_H_
#define MY_MY_TYPE_H_

#include <vector>

namespace my {

//////////////////////////////
//        内部函数指针       //
/////////////////////////////
typedef std::vector<void*> params_t;
typedef std::vector<void*> returns_t;
typedef returns_t (*my_fptr)(const params_t&);

} // namespace my

#endif // MY_MY_TYPE_H_