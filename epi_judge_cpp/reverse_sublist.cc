#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
    shared_ptr<ListNode<int>> dummy_head(new ListNode<int>(0, L));

    auto start_node = L;
    for(; start > 0; start--, finish--) {
        start_node = start_node->next;
    }

    auto node_iter = start_node; 
    while (finish > 0) {
        node_iter
    }

  return nullptr;   
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
