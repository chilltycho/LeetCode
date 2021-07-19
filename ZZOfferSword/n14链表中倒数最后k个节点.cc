#include "ListNode.h"
ListNode *FindKthToTail(ListNode *pHead, int k)
{
    // write code here
    auto s = pHead;
    auto f = pHead;
    while (k)
    {
        if (!f)
            return nullptr;
        f = f->next;
        --k;
    }
    while (f)
    {
        s = s->next;
        f = f->next;
    }
    if (!s)
        return nullptr;
    return s;
}