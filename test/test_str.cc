#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <regex>
#include <gtest/gtest.h>
#include <my/my_common.h>

using namespace std;

TEST(My, StrToHex)
{
  std::string res;
  res = my::str_to_hex("hello world");
  std::cout << res << std::endl;
}

TEST(My, HexToStr)
{
  std::string res;
  res = my::hex_to_str("AABBCCDDEEFF");
  std::cout << res << std::endl;
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}