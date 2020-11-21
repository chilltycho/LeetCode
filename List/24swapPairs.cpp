//给定链表，两辆交换相邻节点。1->2->3->4变为2->1->4->3
#include "utl.h"
ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

ListNode *swapPairs_ite(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto first = head;
    ListNode *preLast = nullptr; //交换链表后的尾节点，指向新交换链表
    ListNode *newHead = head->next;
    while (first != nullptr && first->next != nullptr)
    {
        auto second = first->next;
        auto third = second->next;
        //交换
        first->next = third;
        second->next = first;

        //不为空，前面有交换完成的链表
        if (preLast != nullptr)
            preLast->next = second;
        preLast = first;
        first = third;
    }
    return newHead;
}

//交换节点值
ListNode *swapPairs_2(ListNode *head)
{
    auto temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        auto first = temp->val;
        temp->val = temp->next->val;
        temp->next->val = first;
        temp = temp->next->next;
    }
    return head;
}