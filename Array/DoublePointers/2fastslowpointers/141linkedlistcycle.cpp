#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return slow;
}

int main()
{
    ListNode root(3);
    ListNode n2(2);
    ListNode n0(0);
    ListNode n4(4);

    root.next = &n2;
    n2.next = &n0;
    n0.next = &n4;
    n4.next = &n2;

    cout << hasCycle(&root);
}