#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//判断链表是否为环形链表
bool hasCycle(ListNode *head)
{
    unordered_map<ListNode *, int> m;
    while (head)
    {
        m[head]++;
        if (m[head] > 1)
            return true;
        head = head->next;
    }
    return false;
}

bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}