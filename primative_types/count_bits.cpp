#include "../test_framework/generic_test.h"

/**
 * 5.0 Primitive types boot camp
 * @param x
 * @return # of bits that are set to 1
 */
short CountBits(int x) {
  short num_bits = 0;
  while (x != 0) {
    num_bits += (x & 1); // bitwise-AND
    x >>= 1;
  }
  return num_bits;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  std::cout << GenericTestMain(args, "count_bits", "count_bits.tsv", &CountBits, DefaultComparator{}, param_names)<< std::endl;
  return 0;
}

