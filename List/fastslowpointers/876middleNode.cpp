/*给定带头节点head的非空单链表，返回链表中间节点。若有两个中间节点，返回第二个中间节点*/
#include "../utl.h"
#include <iostream>
using namespace std;

ListNode *middleNode(ListNode *head) {
  auto slow = head;
  auto fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main() {
  vector<int> vi{1, 2, 3, 4, 5};
  auto root = createLinkedList(vi);
  auto res = middleNode(root);
  cout << res->val;
  deleteLinkedList(root);
}

