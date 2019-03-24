#include "../test_framework/generic_test.h"

/**
 * 5.2 Swap bits
 * 1^1=0, 0^1=1
 * @param x
 * @param i
 * @param j
 * @return
 */
long long SwapBits(long long x, int i, int j) {
  if (((x >> i) & 1) == ((x >> j) & 1)) {
    return x;
  } else {
    return x ^ ((1L << i) | (1L << j));
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits, DefaultComparator{}, param_names);
}
