#include <iostream>
#include <vector>
using std::cout;
using std::vector;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

//通过数组创建链表
ListNode *createLinkedList(const vector<int> &arr) {
  if (arr.empty())
    return nullptr;
  ListNode *head = new ListNode(arr[0]);
  ListNode *cur = head;
  for (size_t i = 1; i < arr.size(); i++) {
    cur->next = new ListNode(arr[i]);
    cur = cur->next;
  }
  return head;
}

void printLinkeList(ListNode *head) {
  ListNode *cur = head;
  while (cur != nullptr) {
    cout << cur->val << ' ';
    cur = cur->next;
  }
  cout << "nullptr " << '\n';
}

void deleteLinkedList(ListNode *head) {
  if (head == nullptr)
    delete head;
  ListNode *cur = head;
  ListNode *nex = nullptr;
  while (cur != nullptr) {
    nex = cur->next;
    delete cur;
    cur = nex;
  }
  head = nullptr;
}
// valgrind --leak-check=full  ./leptjson_test 内存泄漏检测

#if 0
struct ListNode
{
    int x;
    shared_ptr<ListNode> next;
    ListNode(int x_) : x(x_), next(nullptr) {}
    ListNode() : x(0), next(nullptr) {}
};

shared_ptr<ListNode> createList(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    auto head = make_shared<ListNode>(nums[0]);
    auto res = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        head->next = make_shared<ListNode>(nums[i]);
        head = head->next;
    }
    return res;
}

void ListPrint(shared_ptr<ListNode> head)
{
    while (head)
    {
        cout << head->x << ' ';
        head = head->next;
    }
}
#endif
