#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <regex>
#include <gtest/gtest.h>
#include <my/my_common.h>

using namespace std;

TEST(My, ReadFile)
{
  std::string dat;
  if (!my::read_file("/home/ga4ss/lynis.log", dat))
    std::cout << dat << std::endl;
  else
    std::cout << "read file failed!" << std::endl;
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}