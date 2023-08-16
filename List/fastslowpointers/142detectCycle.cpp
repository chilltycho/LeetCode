/*找出链表环入口
输入：3->2->0->4->2
输出：pos=1*/
#include "../utl.h"
#include <iostream>
using namespace std;
/*见图*/
ListNode *detectCycle(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    //第一次相遇
    if (slow == fast) 
    {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return fast;
    }
  }
  return nullptr;
}

int main() {
  ListNode root(3);
  ListNode n2(2);
  ListNode n0(0);
  ListNode n4(4);

  root.next = &n2;
  n2.next = &n0;
  n0.next = &n4;
  n4.next = &n2;

  cout << detectCycle(&root)->val;
}


