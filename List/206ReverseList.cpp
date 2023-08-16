//翻转整个链表
#include "utl.h"
using namespace std;

ListNode *reverseList(ListNode *head) {
  ListNode *pre = nullptr;
  ListNode *cur = head;
  while (cur != nullptr) {
    auto t = cur->next;
    cur->next = pre;
    pre = cur;
    cur = t;
  }
  return pre;
}

ListNode *reverseList_re(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *ret = reverseList_re(head->next);
  head->next->next = head;
  head->next = nullptr;
  return ret;
}

ListNode *reverseList_re1(ListNode *head) {
  if (head == nullptr)
    return head;
  ListNode *cur = head;
  while (head->next != nullptr) {
    ListNode *t = head->next->next;
    head->next->next = cur;
    cur = head->next;
    head->next = t;
  }
  return cur;
}

int main() {
  vector<int> vi{1, 2, 3, 4, 5};
  auto root = createLinkedList(vi);
  printLinkeList(reverseList(root));
}