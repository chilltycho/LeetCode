/**
 * 输入链表，从尾到头返回ArrayList
 */
#include "ListNode.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> printListFromTailToHead(ListNode *head) {
  vector<int> res{};
  if (head == nullptr)
    return res;
  while (head != nullptr) {
    res.push_back(head->val);
    head = head->next;
  }
  reverse(res.begin(), res.end());
  return res;
}
