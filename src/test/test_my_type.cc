#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <deque>
#include <iostream>

#include <my_type.h>

int main(int argc, char* argv[]) {
  int i = 0;
  unsigned int j = 0;
  long l = 0;
  unsigned long ll = 0;
  std::cout << "i = " << my::get_support_type<int>() << std::endl;
  std::cout << "j = " << my::get_support_type<unsigned int>() << std::endl;
  std::cout << "l = " << my::get_support_type<long>() << std::endl;
  std::cout << "ll = " << my::get_support_type<unsigned long>() << std::endl;
  return 0;
}