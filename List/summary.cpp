#include "utl.h"

//面试中链表一定都是单链表，应该避免使用：1.加入哑节点 2.使用二级指针
//框架
void foo() {
  ListNode *head(0);
  ListNode *prev = nullptr;
  ListNode *curr = head;
  while (curr != nullptr) {
    if (prev == nullptr) {
      //此时curr为头节点
    } else {
      // curr不是头节点
    }
    prev = curr;
    curr = curr->next;
  }
}

int main() {
  vector<int> vi{1, 3, 4, 5, 6};
  auto head = createLinkedList(vi);
  printLinkeList(head);
}