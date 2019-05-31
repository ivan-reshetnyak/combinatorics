#include <vector>

#include "combinatorics.h"

namespace combin {

number Placements( number m, number n ) {
  if (n > m)
    return 0;

  number Res = 1;
  for (number i = m - n + 1; i <= m; ++i)
    Res *= i;

  return Res;
}

number PlacementsRepeat( number m, number n ) {
  return m.pow(n);
}

number Permutations( number n ) {
  number Res = 1;
  for (number i = 1; i <= n; i++)
    Res *= i;
  return Res;
}

number Combinations( number n, number k ) {
  if (n < k || n == 0)
    return 0;

  std::vector<number> Current((unsigned)(n + 1), 1), Prev((unsigned)(n + 1), 1);
  for (number y = 2; y <= n; y++) {
    for (number x = 1; x <= y - 1; x++)
      Current[(unsigned)x] = Prev[(unsigned)(x - 1)] + Prev[(unsigned)(x)];
    Current.swap(Prev);
  }
  return Prev[(unsigned)k];
}

number Stirling( number n, number k ) {
  if (k == n)
    return 1;
  if (k == 0 || n == 0 || k > n)
    return 0;

  std::vector<number> Current((unsigned)(n + 1), 0), Prev((unsigned)(n + 1), 0);
  Prev[1] = 1;

  for (number y = 2; y <= n; y++) {
    for (number x = 1; x <= y; x++)
      Current[(unsigned)x] = x * Prev[(unsigned)(x)] + Prev[(unsigned)(x - 1)];
    Current.swap(Prev);
  }
  return Prev[(unsigned)k];
}

number Bell( number n ) {
  if (n <= 1)
    return 1;

  std::vector<number> Current((unsigned)(n + 1), 0), Prev((unsigned)(n + 1), 0);
  Prev[1] = 1;

  for (number y = 2; y <= n; y++) {
    for (number x = 1; x <= y; x++)
      Current[(unsigned)x] = x * Prev[(unsigned)(x)] + Prev[(unsigned)(x - 1)];
    Current.swap(Prev);
  }

  number Sum = 0;
  for (const auto &it : Prev)
    Sum += it;
  return Sum;
}

} // End of 'combin' namespace
