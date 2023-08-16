//给定单链表L:L0->L1->...->Ln-1->Ln将其重拍列为L0->Ln->L1->Ln-1->L2->Ln-2
#include "utl.h"
using namespace std;
void reorderList(ListNode *head) {
  if (head == nullptr)
    return;
  vector<ListNode *> vec;
  ListNode *node = head;
  while (node != nullptr) {
    vec.push_back(node);
    node = node->next;
  }
  int i = 0;
  int j = vec.size() - 1;
  while (i < j) {
    vec[i]->next = vec[j];
    i++;
    if (i == j)
      break;
    vec[j]->next = vec[i];
    j--;
  }
  vec[i]->next = nullptr;
}

ListNode *findMiddle(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

ListNode *reverseList(ListNode *head) {
  ListNode *pre = nullptr;
  ListNode *cur = head;
  ListNode *ne;
  while (cur != nullptr) {
    ne = cur->next;
    cur->next = pre;
    pre = cur;
    cur = ne;
  }
  return pre;
}

void mergeList(ListNode *l1, ListNode *l2) {
  ListNode *l1_tmp;
  ListNode *l2_tmp;
  while (l1 != nullptr && l2 != nullptr) {
    l1_tmp = l1->next;
    l2_tmp = l2->next;

    l1->next = l2;
    l1 = l1_tmp;

    l2->next = l1;
    l2 = l2_tmp;
  }
}

void reorderList_1(ListNode *head) {
  if (head == nullptr)
    return;
  ListNode *mid = findMiddle(head);
  ListNode *l1 = head;
  ListNode *l2 = mid->next;
  mid->next = nullptr;
  l2 = reverseList(l2);
  mergeList(l1, l2);
}

int main() {
  vector<int> vi{1, 2, 3, 4};
  auto head = createLinkedList(vi);
  reorderList_1(head);
  printLinkeList(head);
}