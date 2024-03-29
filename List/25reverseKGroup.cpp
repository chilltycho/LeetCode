//给定链表，每k个节点进行翻转，若节点整数不是k整数倍，剩余节点顺序不变
#include "utl.h"
//反转[a,b)
ListNode *reverse(ListNode *a, ListNode *b) {
  ListNode *pre = nullptr;
  auto cur = a;
  while (cur != b) {
    auto nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  return pre;
}

ListNode *reverse_re(ListNode *a, ListNode *b) {
  if (!a || !a->next || a == b || a->next == b) {
    return a;
  }
  auto newh = reverse_re(a->next, b);
  a->next->next = a;
  a->next = b;
  return newh;
}

ListNode *reverseKGroup_1(ListNode *head, int k) {
  if (head == nullptr) {
    return head;
  }
  auto a = head;
  auto b = head;
  for (int i = 0; i < k; i++) {
    if (b == nullptr) {
      return head;
    }
    b = b->next;
  }
  auto newHead = reverse_re(a, b);
  a->next = reverseKGroup_1(b, k);
  return newHead;
}

int main() {
  vector<int> vi{1, 2, 3, 4, 5};
  auto root = createLinkedList(vi);
  auto res = reverseKGroup_1(root, 2);
  printLinkeList(res);
}
