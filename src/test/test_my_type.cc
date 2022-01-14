#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <string>
#include <vector>
#include <deque>
#include <iostream>

#include <my_type.h>

int main(int argc, char* argv[]) {
  std::cout << "int = " << my::get_support_type<int>() << std::endl;
  std::cout << "unsigned int = " << my::get_support_type<unsigned int>() << std::endl;
  std::cout << "long = " << my::get_support_type<long>() << std::endl;
  std::cout << "unsigned long = " << my::get_support_type<unsigned long>() << std::endl;
  std::cout << "size_t = " << my::get_support_type<size_t>() << std::endl;
  std::cout << "std::string = " << my::get_support_type<std::string>() << std::endl;
  // std::cout << my::get_type_name<std::string>() << std::endl;
  return 0;
}