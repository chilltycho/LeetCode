#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *curnext = curr->next;
#if 0
        if (prev == nullptr) //curr为头
        {
            curr->next = prev;
        }
        else
        {
            curr->next = prev;
        }
#endif
        curr->next=prev;
        prev = curr;
        curr = curnext;
    }
    return prev;
}

void print(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << ' ';
        prev = curr;
        curr = curr->next;
    }
}
int main()
{
    ListNode head(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    head.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    //print(&head);

    ListNode *newlist=reverseList(&head);
    print(newlist);
}