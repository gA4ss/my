#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <regex>
#include <gtest/gtest.h>
#include <my/my_input.h>

using namespace std;

TEST(Sym, Input)
{
  EXPECT_TRUE(my::is_integer("5"));
  EXPECT_TRUE(my::is_integer("-4"));
  EXPECT_TRUE(my::is_integer("0"));
  EXPECT_TRUE(my::is_hex_integer("0xAabbc56"));
  EXPECT_TRUE(my::is_hex_integer("xBB4466"));
  EXPECT_TRUE(my::is_number("12321"));
  EXPECT_TRUE(my::is_real("5.0"));
  EXPECT_TRUE(my::is_real("-0.34"));
  EXPECT_TRUE(my::is_real(".45"));
  EXPECT_TRUE(my::is_number("-12321.45"));
  EXPECT_TRUE(my::is_variate("x12"));
  EXPECT_TRUE(my::is_variate("xy"));
  EXPECT_TRUE(my::is_variate("x"));
  EXPECT_TRUE(my::is_variate("__x"));
  EXPECT_TRUE(my::is_variate("__x1"));
  EXPECT_FALSE(my::is_variate("5x"));
  EXPECT_FALSE(my::is_variate(".x"));
  EXPECT_EQ(my::type_of_string("85xyz."), kStrTypeErr);
}

// TEST(Sym, Regex)
// {
//   string str = "sigalhu233";

//   regex r("[a-z0-9]+");
//   cout << "正则表达式：[a-z0-9]+" << endl;
//   if (regex_match(str, r))
//     cout << "字符串：" << str << " 匹配成功！" << endl;
//   else
//     cout << "字符串：" << str << " 匹配失败！" << endl;

//   cout << endl
//        << "正则表达式：\\d+" << endl;
//   if (regex_match(str, regex("\\d+")))
//     cout << "字符串：" << str << " 匹配成功！" << endl;
//   else
//     cout << "字符串：" << str << " 匹配失败！" << endl;

//   cout << endl
//        << "正则表达式：\\d+" << endl;
//   if (regex_match(str.begin() + 7, str.end(), regex("\\d+")))
//     cout << "字符串：" << &str[7] << " 匹配成功！" << endl;
//   else
//     cout << "字符串：" << &str[7] << " 匹配失败！" << endl;

//   smatch sm;
//   cout << endl
//        << "正则表达式：([a-z]+)(\\d+)" << endl;
//   if (regex_match(str.cbegin() + 5, str.cend(), sm, regex("([a-z]+)(\\d+)")))
//   {
//     cout << "字符串：" << &str[5] << " 匹配成功！" << endl;
//     cout << "匹配字符串个数：" << sm.size() << endl;
//     cout << "分别为：";
//     for (auto aa : sm)
//       cout << aa.str() << " ";
//     cout << endl;
//   }
//   else
//     cout << "字符串：" << &str[5] << " 匹配失败！" << endl;

//   cmatch cm;
//   cout << endl
//        << "正则表达式：([a-z]+)(\\d+)" << endl;
//   if (regex_match(str.c_str(), cm, regex("([a-z]+)(\\d+)")))
//   {
//     cout << "字符串：" << str << " 匹配成功！" << endl;
//     cout << "匹配字符串个数：" << cm.size() << endl;
//     cout << "分别为：";
//     for (auto aa : cm)
//       cout << aa.str() << " ";
//     cout << endl;
//   }
//   else
//     cout << "字符串：" << str << " 匹配失败！" << endl;
// }

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}