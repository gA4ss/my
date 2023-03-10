#include <my/my_input.h>

#include <iostream>
#include <regex>

namespace my
{
  static std::regex __r_var("[a-zA-Z_][a-zA-Z0-9_]*");
  static std::regex __r_dec_int("^-?[0-9]+$");
  static std::regex __r_hex_int("^-?([xX]?|0[xX]?)[0-9a-fA-F]+$");
  static std::regex __r_real("^-?([1-9]*\\.[0-9]*|0\\.[1-9]+|0?\\.0+|0)$");

  int type_of_string(std::string s)
  {
    if (is_variate(s))
      return kStrTypeVar;
    // else if (is_dec_integer(s))
    //   return kStrTypeDecInt;
    // else if (is_hex_integer(s))
    //   return kStrTypeHexInt;
    else if (is_integer(s))
      return kStrTypeInt;
    else if (is_real(s))
      return kStrTypeReal;
    return kStrTypeErr;
  }

  bool is_variate(std::string s)
  {
    return std::regex_match(s, __r_var);
  }

  bool is_hex_integer(std::string s)
  {
    return std::regex_match(s, __r_hex_int);
  }

  bool is_dec_integer(std::string s)
  {
    return std::regex_match(s, __r_dec_int);
  }

  bool is_real(std::string s)
  {
    return std::regex_match(s, __r_real);
  }

  bool is_integer(std::string s)
  {
    return is_dec_integer(s) || is_hex_integer(s);
  }

  bool is_number(std::string s)
  {
    return is_integer(s) || is_real(s);
  }

} // namespace my