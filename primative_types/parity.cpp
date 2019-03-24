#include "../test_framework/generic_test.h"

/**
 * 5.1 Computing parity
 * @param x
 * @return 1 if # of 1s is odd, else 0
 */
// T(n) = O(n)
short Parity(unsigned long long x) {
  short p = 0;
  while (x) {
    p ^= (x & 1); // bitwise-XOR
    x >>= 1;
  }
  return p;
}

// T(n) = O(k)
short Parity2(unsigned long long x) {
  short p = 0;
  while (x != 0) {
    p ^= 1;
    x &= (x - 1); // replace the lsb with 0
  }
  return p;
}

// TODO
// T(n) = O(log n)
short Parity3(unsigned long long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return (short)(x & 0x1);
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  std::cout << GenericTestMain(args, "parity", "parity.tsv", &Parity, DefaultComparator{}, param_names) << std::endl;
  std::cout << GenericTestMain(args, "parity", "parity.tsv", &Parity2, DefaultComparator{}, param_names) << std::endl;
  std::cout << GenericTestMain(args, "parity", "parity.tsv", &Parity3, DefaultComparator{}, param_names) << std::endl;
  return 0;
}
