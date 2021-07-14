//给定链表，每k个节点进行翻转，若节点整数不是k整数倍，剩余节点顺序不变
#include "utl.h"
//反转[a,b)
ListNode *reverse(ListNode *a, ListNode *b)
{
    ListNode *pre = nullptr;
    auto cur = a;
    while (cur != b)
    {
        auto nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode *reverse_re(ListNode *l, ListNode *r)
{
    if (l == r)
        return l;
    auto node = reverse(l->next, r);
    l->next->next = l;
    l->next = nullptr;
    return node;
}

ListNode *reverseKGroup_1(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    auto a = head;
    auto b = head;
    for (int i = 0; i < k; i++)
    {
        if (b == nullptr)
            return head;
        b = b->next;
    }
    auto newHead = reverse_re(a, b);
    a->next = reverseKGroup_1(b, k);
    return newHead;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    auto a = head;
    auto b = head;
    for (int i = 1; i < k; i++)
    {
        b = b->next;
        if (b == nullptr)
            return head;
    }
    auto nb = b->next;
    auto newHead = reverse(a, b);
    a->next = reverseKGroup(nb, k);
    return newHead;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = createLinkedList(vi);
    auto res = reverseKGroup_1(root, 3);
    printLinkeList(res);
}