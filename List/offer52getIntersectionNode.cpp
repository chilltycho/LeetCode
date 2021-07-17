//输入两个链表，找出它们第一个公共节点
#include "utl.h"
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    auto h1 = headA;
    auto h2 = headB;
    while (h1 != h2)
    {
        h1 = (h1 == nullptr ? headB : h1->next);
        h2 = (h2 == nullptr ? headA : h2->next);
    }
    return h1;
}

int main()
{
}