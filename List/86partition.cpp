//给定链表和特定值x，对链表分割，使所有小于x的节点都在大于或等于x的节点之前,不改变相对顺序
#include "utl.h"

ListNode *partition(ListNode *head, int x) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *before_head = new ListNode(0);
  ListNode *before = before_head;
  ListNode *after_head = new ListNode(0);
  ListNode *after = after_head;
  while (head != nullptr) {
    if (head->val < x) {
      before->next = head;
      before = before->next;
    } else {
      after->next = head;
      after = after->next;
    }
    head = head->next;
  }
  before->next = after_head->next;
  after->next = nullptr;
  return before_head->next;
}

ListNode *partition_1(ListNode *head, int x) {
  if (head == nullptr)
    return nullptr;
  ListNode *lhead = nullptr;
  ListNode *ghead = nullptr;
  ListNode *liter = nullptr;
  ListNode *giter = nullptr;
  while (head != nullptr) {
    if (head->val < x) {
      if (lhead == nullptr) {
        lhead = head;
        liter = head;
      } else {
        liter->next = head;
        liter = liter->next;
      }
    } else {
      if (ghead == nullptr) {
        ghead = head;
        giter = ghead;
      } else {
        giter->next = head;
        giter = giter->next;
      }
    }
    head = head->next;
  }
  if (lhead == nullptr) {
    giter->next = nullptr;
    return ghead;
  }
  if (ghead == nullptr) {
    liter->next = nullptr;
    return lhead;
  }
  liter->next = ghead;
  giter->next = nullptr;
  return lhead;
}

int main() {
  vector<int> vi{1, 4, 3, 2, 5, 2};
  auto head = createLinkedList(vi);
  auto res = partition_1(head, 3);
  printLinkeList(res);
}
