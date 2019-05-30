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

  cout << (unsigned)Combinations(8, 3) << endl;
  cout << (unsigned)Combinations(30, 10) << endl;

  _getch();
  return 0;
}

TEST( combs, placements ) {
  ASSERT_TRUE(Placements(1, 1) == 1);
  ASSERT_TRUE(Placements(2, 2) == 2);
  ASSERT_TRUE(Placements(3, 3) == 6);
  ASSERT_TRUE(Placements(4, 2) == 12);
}

TEST( combs, stirling ) {
  ASSERT_TRUE(Stirling(3, 2) == 3);
  ASSERT_TRUE(Stirling(6, 4) == 65);
  ASSERT_TRUE(Stirling(8, 6) == 266);
  ASSERT_TRUE(Stirling(9, 9) == 1);
}

TEST( combs, bell ) {
  ASSERT_TRUE(Bell(2) == 2);
  ASSERT_TRUE(Bell(3) == 5);
  ASSERT_TRUE(Bell(4) == 15);
  ASSERT_TRUE(Bell(5) == 52);
}

TEST( combs, placements_rep ) {
  ASSERT_TRUE(PlacementsRepeat(1, 1) == 1);
  ASSERT_TRUE(PlacementsRepeat(2, 2) == 4);
  ASSERT_TRUE(PlacementsRepeat(3, 3) == 27);
  ASSERT_TRUE(PlacementsRepeat(4, 2) == 16);
}

TEST( combs, permutations ) {
  ASSERT_TRUE(Permutations(0) == 1);
  ASSERT_TRUE(Permutations(1) == 1);
  ASSERT_TRUE(Permutations(2) == 2);
  ASSERT_TRUE(Permutations(10) == 3628800);
  ASSERT_TRUE(Permutations(12) == 479001600);
}

TEST( combs, combinations ) {
  ASSERT_TRUE(Combinations(0, 1) == 0);
  ASSERT_TRUE(Combinations(1, 1) == 1);
  ASSERT_TRUE(Combinations(3, 2) == 3);
  ASSERT_TRUE(Combinations(4, 3) == 4);
  ASSERT_TRUE(Combinations(4, 2) == 6);
}

TEST( group_number, pow1 ) {
  ASSERT_TRUE(number(2).pow(10) == 1024);
}

TEST( group_number, pow2 ) {
  try {
    number(2).pow(32);
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on multiplication!"));
  }
}

TEST( group_number, add1 ) {
  try {
    number(-1) + number(1);
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on addition!"));
  }
}

TEST( group_number, add2 ) {
  try {
    number(0xFFFFFFF0) + number(0x00000010);
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on addition!"));
  }
}

TEST( group_number, sub1 ) {
  try {
    number(1) - number(2);
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on subtraction!"));
  }
}

TEST( group_number, sub2 ) {
  try {
    number(0xAFFFFFF0) - number(0xF0000010);
    ASSERT_TRUE(false);
  } catch (std::exception Exc) {
    ASSERT_TRUE(Exc.what() == std::string("UINT 32 overflow on subtraction!"));
  }
}
