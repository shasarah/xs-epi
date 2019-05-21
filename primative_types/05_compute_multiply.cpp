#include "../test_framework/generic_test.h"

unsigned long long Add (unsigned long long a, unsigned long long b) {
  unsigned long long carry = 0;
  while (b) {
    carry = (a & b) << 1;
    a = a ^ b;
    b = carry;
  }
  return a;
}

unsigned long long Multiply (unsigned long long a, unsigned long long b) {
  unsigned long long result = 0;
  while (b) {
    if (b & 1) {
      result = Add(a, result); // result += a;
    }
    a <<= 1;
    b >>= 1;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "multiply.cc","primitive_multiply.tsv", &Multiply,DefaultComparator{}, param_names);
}
