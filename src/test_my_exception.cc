#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <deque>
#include <iostream>

#include <my_common.h>

void foo() {
  invalid_arguments_exception();
  //my_assert(a==0, "%s", "haha!");
}

int main(int argc, char* argv[]) {
  try {
    foo();
  } catch (my::MyException &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}