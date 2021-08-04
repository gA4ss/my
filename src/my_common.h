#ifndef MY_MY_COMMON_H_
#define MY_MY_COMMON_H_

#include <cmath>
#include <cstring>
#include <cassert>

#include <string>
#include <list>
#include <deque>
#include <vector>
#include <utility>      // pair
#include <set>
#include <map>
#include <algorithm>

#include <my/my_compile.h>
#include <my/my_error.h>
#include <my/my_exception.h>
#include <my/my_log.h>
#include <my/my_uuid.h>
#include <my/my_object.h>
#include <my/my_type.h>

namespace my {

//////////////////////////////
//         辅助函数         //
/////////////////////////////
void tokenize(std::string const& str, std::vector<std::string>& out, std::string delims=",\r\n\t ");
std::string get_filename(std::string path);
std::string get_real_path(const std::string& path);
size_t get_filesize(std::string path);
int read_file(std::string path, std::string& txt);
bool get_environment_variable(std::string &str, const char* environment_variable);

//////////////////////////////
//         异常函数         //
/////////////////////////////
#define invalid_arguments_exception() { throw my::InvalidArgumentsException(__FILE__, __LINE__, __FUNCTION__); }
#define out_of_range_exception() { throw my::OutOfRangeException(__FILE__, __LINE__, __FUNCTION__); }
#define execute_error_exception(con,ecd) { throw mysym::core::ExecuteErrorException((con), (ecd), __FILE__, __LINE__, __FUNCTION__); }
#define internal_execute_exception(con) { throw mysym::core::InternalExecuteException((con), __FILE__, __LINE__, __FUNCTION__); }

#define my_assert(exp, format, ...) { \
  if (!(static_cast<bool>(exp))) throw my::AssertException(__FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
}

} // namespace my

#endif // MY_MY_COMMON_H_