#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <deque>
#include <iostream>

#include <my_uuid.h>

int main(int argc, char* argv[]) {
  std::string id = my::uuid();
  std::cout << id << std::endl;
  return 0;
}