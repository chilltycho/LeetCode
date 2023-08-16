#include "../utl.h"
#include <stack>
using namespace std;
ListNode *reverse(ListNode *root) {
  if (!root || !root->next)
    return root;
  auto res = reverse(root->next);
  root->next->next = root;
  root->next = nullptr;
  return res;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  l1 = reverse(l1);
  l2 = reverse(l2);
  ListNode *res = new ListNode(-1);
  auto cur = res;
  int carry = 0;
  while (l1 || l2) {
    int x = l1 ? l1->val : 0;
    int y = l2 ? l2->val : 0;
    int sum = x + y + carry;
    carry = sum / 10;
    cur->next = new ListNode(sum % 10);
    cur = cur->next;
    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
  }
  if (carry > 0)
    cur->next = new ListNode(carry);
  return reverse(res->next);
}

void print(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val << ' ';
    prev = curr;
    curr = curr->next;
  }
}

int main() {
  vector<int> v1{7, 2, 4, 3};
  auto r1 = createLinkedList(v1);
  vector<int> v2{5, 6, 4};
  auto r2 = createLinkedList(v2);
  auto res = addTwoNumbers(r1, r2);
  printLinkeList(res);
}


