#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
    if (x & 1) {
        unsigned long long x_mask = (~x) & ~(~x - 1); //select the lsb zero bit
        x ^= x_mask;
        x_mask = x_mask >> 1; //select the immediately preceding 1 bit
        x ^= x_mask;
    }
    else {
        unsigned long long x_mask = x & ~(x - 1); // Selects the lsb one bit
        x_mask = x_mask >> 1; // selects the immediately preceeding 0 bit 
        x &= (x - 1); // flip the lsb one bit
        x ^= x_mask; // flip the precedding one bit
    }
    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
