#ifndef MY_MY_INPUT_H_
#define MY_MY_INPUT_H_

#include <string>

namespace my {

#define kStrTypeErr     0xFFFFFFFF
#define kStrTypeVar     1
#define kStrTypeDecInt  2
#define kStrTypeHexInt  3
#define kStrTypeReal    4
#define kStrTypeInt     5
#define kStrTypeNum     6

int type_of_string(std::string s);
bool is_variate(std::string s);
bool is_dec_integer(std::string s);
bool is_hex_integer(std::string s);
bool is_integer(std::string s);
bool is_real(std::string s);
bool is_number(std::string s);

} // namespace my

#endif // MY_MY_INPUT_H_