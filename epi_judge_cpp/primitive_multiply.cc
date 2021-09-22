#include "test_framework/generic_test.h"
unsigned long long Add(unsigned long long x, unsigned long long y) {
    unsigned long long sum = 0, carry = 0, tmp_x = x, tmp_y = y, k = 1;

    while (tmp_x || tmp_y) {
        unsigned long long bit_x = x & k, bit_y = y & k;
        unsigned long long carry_out = (bit_x & bit_y) | (bit_x & carry) | (bit_y & carry);
        sum |= (bit_x ^ bit_y ^ carry);
        carry = carry_out << 1, k <<= 1, tmp_x >>= 1, tmp_y >>= 1;
    }
    return sum | carry;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
    unsigned long long prod = 0;
    while (y) {
        if (y & 1) {
            prod = Add(prod, x);
        }
        x <<= 1; y >>= 1;
    }
    return prod;
}

 
int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
