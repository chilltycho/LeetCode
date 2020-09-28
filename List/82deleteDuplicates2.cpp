#include "utl.h"
//已经排好序的数组，删除所有含重复数字的节点
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *dumHead = new ListNode(INTMAX_MAX);
    dumHead->next = head;
    ListNode *prev = dumHead;
    while (prev != nullptr && prev->next != nullptr)
    {
        ListNode *curr = prev->next;
        if ((curr->next) == nullptr || curr->next->val != curr->val)
            prev = curr;
        else
        {
            while (curr->next && curr->next->val == curr->val)
                curr = curr->next;
            prev->next = curr->next;
        }
    }
    return dumHead->next;
}

ListNode *deleteDuplicates_1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *dumHead = new ListNode(-1);
    dumHead->next = head;
    ListNode *prev = dumHead;
    ListNode *curr = head;
    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->val == curr->next->val)
        {
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            prev->next = curr->next;
            curr=curr->next;
        }
        else
        {
            prev = curr;
            curr = prev->next;
        }
    }
    return dumHead->next;
}

int main()
{
    vector<int> v1{1, 2, 3, 3, 4, 4, 5};
    printLinkeList(deleteDuplicates_1(createLinkedList(v1))); //应输出1->2->5
    vector<int> v2{1, 1, 1, 2, 3};
    printLinkeList(deleteDuplicates_1(createLinkedList(v2))); //应输出2->3
    vector<int> v3{1, 1, 2, 2};
    printLinkeList(deleteDuplicates_1(createLinkedList(v3)));
}