#include "ListNode.h"
using namespace std;

ListNode *ReverseList(ListNode *pHead) {
  if (pHead == nullptr || pHead->next == nullptr)
    return pHead;
  auto res = ReverseList(pHead->next);
  pHead->next->next = pHead;
  pHead->next = nullptr;
  return res;
}

ListNode *ReverseList_1(ListNode *pHead) {
  ListNode *pre = nullptr;
  auto cur = pHead;
  while (cur) {
    auto tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}