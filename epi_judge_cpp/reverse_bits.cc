#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
    long long is_diff_mask = (x >> i & 1) ^ (x >> j & 1);
    x ^= is_diff_mask << i;
    x ^= is_diff_mask << j;
    return x;
}

unsigned long long ReverseBits(unsigned long long x) {
    for (int i = 0, j = sizeof(x) * CHAR_BIT - 1; i < j; i++, j--) {
        x = SwapBits(x, i, j);
    }
    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
