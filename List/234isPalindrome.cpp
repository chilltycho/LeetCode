#include "utl.h"
// 1->2->2->1
bool isPalindrome(ListNode *head) {
  vector<int> vals;
  ListNode *cur = head;
  while (cur != nullptr) {
    vals.push_back(cur->val);
    cur = cur->next;
  }
  int front = 0, back = vals.size() - 1;
  while (front < back) {
    if (vals[front] != vals[back])
      return false;
    front++;
    back--;
  }
  return true;
}

ListNode *reverse_re(ListNode *root) {
  if (root == nullptr || root->next == nullptr)
    return root;
  auto res = reverse_re(root->next);
  root->next->next = root;
  root->next = nullptr;
  return res;
}
//从中间位置反转列表。
bool isPalindrome_1(ListNode *head)  {
  if (head == nullptr || head->next == nullptr)
    return true;
  ListNode *slow = head, *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  } //此时slow指向中心节点或中心偏后节点

  auto curNode = reverse_re(slow);
  while (head && curNode) {
    if (head->val != curNode->val)
      return false;
    head = head->next;
    curNode = curNode->next;
  }
  return true;
}

int main() {
  vector<int> vi{1, 2, 3, 2, 1};
  auto head = createLinkedList(vi);
  cout << isPalindrome(head);
}
