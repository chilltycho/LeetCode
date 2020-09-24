#include "utl.h"

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *curnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curnext;
    }
    return prev;
}

ListNode *reverseList_re(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *nextNode = head->next;
    ListNode *newHead = reverseList_re(nextNode);
    nextNode->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(vi);
    auto res = reverseList_re(head);
    printLinkeList(res);
}