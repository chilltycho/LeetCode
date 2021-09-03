#include "utl.h"

ListNode *reverseList(ListNode *head, int n)
{
    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *curnext = nullptr;
    while (n)
    {
        curnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curnext;
        --n;
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
    for (int i = 1; i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr) //头节点
        return reverseList(head, n - m);
    else
    {
        prev->next = reverseList(curr, n - m);
        return head;
    }
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto head = createLinkedList(vi);
    auto res = reverseBetween(head, 2, 4);
    printLinkeList(res);
}