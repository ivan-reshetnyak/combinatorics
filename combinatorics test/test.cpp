#include <cstdlib>
#include <conio.h>

#include <iostream>
#include <string>

#include <gtest/gtest.h>
#include <memhooks/memhooks.h>

#include "../combinatorics/combinatorics.h"

using namespace combin;

using std::cout;
using std::endl;

int main( int argc, char **argv ) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();

  _getch();
  return 0;
}

TEST( overflows, add1 ) {
  number A(-1), B(1);

  try {
    A + B;
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on addition!"));
  }
}

TEST( overflows, add2 ) {
  number A(0xFFFFFFF0), B(0x00000010);

  try {
    A + B;
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on addition!"));
  }
}

TEST( overflows, sub1 ) {
  number A(1), B(2);

  try {
    A - B;
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on subtraction!"));
  }
}

TEST( overflows, sub2 ) {
  number A(0xAFFFFFF0), B(0xF0000010);

  try {
    A - B;
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on subtraction!"));
  }
}
