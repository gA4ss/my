#ifndef MY_MY_COMMON_H_
#define MY_MY_COMMON_H_

#include <cmath>
#include <cstring>
#include <cassert>

#include <memory>
#include <string>
#include <list>
#include <deque>
#include <vector>
#include <utility>      // pair
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

#include <my/my_compile.h>
#include <my/my_error.h>
#include <my/my_exception.h>
#include <my/my_log.h>
#include <my/my_debug.h>
#include <my/my_input.h>

namespace my {

//////////////////////////////
//         辅助函数         //
/////////////////////////////
void tokenize(std::string const& str, std::vector<std::string>& out, std::string delims=",\r\n\t ");
std::string get_filename(std::string path);
std::string get_real_path(const std::string& path);
size_t get_filesize(std::string path);
int read_file(std::string path, std::string& txt);
int read_file(std::string path, unsigned char *buf, size_t *osize);
bool get_environment_variable(std::string &str, const char* environment_variable);
std::string str_to_hex(const std::string& data, bool bigcase=false);
std::string hex_to_str(const std::string& str);

//////////////////////////////
//         异常函数         //
/////////////////////////////
#define invalid_arguments_exception(format, ...) { throw my::MyException("Invalid Arguments", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define out_of_range_exception(format, ...) { throw my::MyException("Out of Range", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define execute_error_exception(format, ...) { throw my::MyException("Execute Error", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define internal_execute_exception(format, ...) { throw my::MyException("Internal Execute", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
#define xxx_can_not_convert_to_yyy_exception(xxx, yyy) { throw my::MyException("Type Convert", __FILE__, __LINE__, __FUNCTION__, "%s -> %s", (xxx), (yyy)); }

#define my_assert(exp, format, ...) { \
  if (!(static_cast<bool>(exp))) throw my::MyException("Assert", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
}

} // namespace my

#endif // MY_MY_COMMON_H_