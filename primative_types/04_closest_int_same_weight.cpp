#include "../test_framework/generic_test.h"

/**
 * 5.4 Find a closest integer with the same weight (# of 1s)
 * @param x
 * @return
 */
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  short s = sizeof(x) * CHAR_BIT;
  for (int i = 0; i < s - 1; ++i) {
    if (((x >> i) & 1) != ((x >> (i + 1) & 1))) {
      x ^= (1L << i) | (1L << (i + 1));
      return x;
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc","closest_int_same_weight.tsv", &ClosestIntSameBitCount,DefaultComparator{}, param_names);
}
