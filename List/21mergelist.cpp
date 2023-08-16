#include "utl.h"
#include <vector>
using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if (!l1) {
    return l2;
  }
  if (!l2) {
    return l1;
  }
  if (l1->val < l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}

ListNode *mergeTwoLists_1(ListNode *l1, ListNode *l2) {
  ListNode *prehead = new ListNode(-1);
  ListNode *prev = prehead;
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val < l2->val) {
      prev->next = l1;
      l1 = l1->next;
    } else {
      prev->next = l2;
      l2 = l2->next;
    }
    prev = prev->next;
  }
  prev->next = l1 == nullptr ? l2 : l1;
  return prehead->next;
}

int main() {
  vector<int> v1{1, 3, 5, 7};
  auto r1 = createLinkedList(v1);
  vector<int> v2{2, 4, 4};
  auto r2 = createLinkedList(v2);
  auto res = mergeTwoLists_1(r1, r2);
  printLinkeList(res);
}
