#include "utl.h"
//给定单链表，将第奇数个节点和第偶数个节点分别排在一起
ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  auto odd = head;
  auto evenh = head->next;
  auto even = evenh;
  while (odd != nullptr && odd->next != nullptr && odd->next->next != nullptr) {
    odd->next = even->next;
    odd = even->next;
    even->next = odd->next;
    even = odd->next;
  }
  odd->next = evenh;
  return head;
}

ListNode *oddEvenList_1(ListNode *head) {
  if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
    return head;
  auto Oite = head, Eite = head->next, Ehead = head->next;
  auto ite = Eite->next;
  while (ite != nullptr && ite->next != nullptr) {
    Oite->next = ite;
    Oite = Oite->next;
    Eite->next = ite->next;
    Eite = Eite->next;
    ite = ite->next->next;
  }
  if (ite == nullptr) {
    Oite->next = Ehead;
    Eite->next = nullptr;
    return head;
  }
  Oite->next = ite;
  auto temp = head->next->val;
  ite->next = Ehead;
  Eite->next = nullptr;
  return head;
}

int main() {
  vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8};

  auto head = createLinkedList(vi);
  auto res = oddEvenList_1(head);
  printLinkeList(res); // 1,3,5,2,4

  vector<int> vi1{2, 1, 3, 5, 6, 4, 7};
  auto head1 = createLinkedList(vi1);
  auto res1 = oddEvenList_1(head1);
  printLinkeList(res1); // 2,3,6,7,1,5,4
}

