#include <vector>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//通过数组创建链表
ListNode *createLinkedList(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < arr.size(); i++)
    {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLinkeList(ListNode *head)
{
    ListNode *cur = head;
    while (cur != nullptr)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << "nullptr " << endl;
}

void deleteLinkedList(ListNode *head)
{
    if (head == nullptr)
        free(head);
    ListNode *cur = head;
    ListNode *nex = nullptr;
    while (cur != nullptr)
    {
        nex = cur->next;
        free(cur);
        cur = nex;
    }
    head=nullptr;
}
//valgrind --leak-check=full  ./leptjson_test 内存泄漏检测