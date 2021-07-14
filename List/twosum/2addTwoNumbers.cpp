//给出两非空链表表示两非负整数，将两个数相加起来，返回新链表表示它们的和
#include "utl.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    ListNode *resHead = new ListNode(0);
    auto cur = resHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;
    }
    if (carry > 0)
        cur->next = new ListNode(carry);
    return resHead->next;
}

int main()
{
    vector<int> v1{2, 4, 3};
    vector<int> v2{5, 6, 4};
    auto l1 = createLinkedList(v1);
    auto l2 = createLinkedList(v2);
    auto l3 = addTwoNumbers(l1, l2);
    printLinkeList(l3); //7->0>8
}