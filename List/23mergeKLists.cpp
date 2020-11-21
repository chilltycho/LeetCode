//合并k个升序链表
#include "utl.h"
ListNode *merge2Lists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1->val <= l2->val)
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
//时间复杂度O(k^2 n), 设每个链表最长为n，k个链表。
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *ans = nullptr;
    for (size_t i = 0; i < lists.size(); i++)
        ans = merge2Lists(ans, lists[i]);
    return ans;
}

//分治，O(knlogk)
ListNode *merge(vector<ListNode *> &list, int l, int r)
{
    if (l == r)
        return list[l];
    if (l > r)
        return nullptr;
    int mid = (l + r) / 2;
    return merge2Lists(merge(list, l, mid), merge(list, mid + 1, r));
}
ListNode *mergeKLists_1(vector<ListNode *> &list)
{
    return merge(list, 0, list.size() - 1);
}
int main()
{
}