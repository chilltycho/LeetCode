#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head, int n)
{
    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *curnext = nullptr;
    while (n--)
    {
        curnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curnext;
    }
    head->next = curnext;
    return prev;
}

//反转从第m个节点到第n个节点, 1<=m<=n<=链表长度
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (m == n)
        return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    int i;
    for (i = 1; i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr)
        return reverseList(head, n - m);
    else
    {
        prev->next = reverseList(curr, n - m);
        return head;
    }
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

    ListNode *newlist = reverseBetween(&head, 1, 4);
    print(newlist);
}