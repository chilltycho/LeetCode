#include "utl.h"
using namespace std;
ListNode *findMid(ListNode *head)
{
    auto s = head, f = head;
    ListNode *pre = nullptr;
    while (f && f->next)
    {
        pre = s;
        s = s->next;
        f = f->next->next;
    }
    pre->next = nullptr;
    return s;
}

ListNode *merge2Lists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = merge2Lists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge2Lists(l1, l2->next);
        return l2;
    }
}

ListNode *mergeSort(ListNode *head)
{
    if (!head || !(head->next))
        return head;
    auto m = findMid(head);
    auto l1 = mergeSort(head);
    auto l2 = mergeSort(m);
    return merge2Lists(l1, l2);
}

ListNode *sortList(ListNode *head)
{
    return mergeSort(head);
}

int main()
{
    vector<int> vi{5,3,4,2,1};
    auto root=createLinkedList(vi);
    auto res = sortList(root);
    printLinkeList(res);
}