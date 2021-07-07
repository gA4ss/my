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
#include <map>
#include <algorithm>

#include <my_compile.h>
#include <my_error.h>
#include <my_exception.h>
#include <my_log.h>
#include <my_uuid.h>

namespace my {

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
#define divisor_is_zero_exception() { throw my::DivisorIsZeroException(__FILE__, __LINE__, __FUNCTION__); }
#define operand_is_nan_exception() { throw my::OperandIsNanException(__FILE__, __LINE__, __FUNCTION__); }
#define operand_is_infinite_exception() { throw my::OperandIsInfiniteException(__FILE__, __LINE__, __FUNCTION__); }
#define my_assert(exp, format, ...) { \
  if (!(static_cast<bool>(exp))) throw my::AssertException(__FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
}

} // namespace my

#endif // MY_MY_COMMON_H_