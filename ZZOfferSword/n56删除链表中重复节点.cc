struct ListNode
{
    ListNode *next;
    ListNode(int);
    int val;
};

ListNode *deleteDuplicates1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode phead(-1);
    phead.next = head;

    ListNode *pre = &phead;
    ListNode *cur = head;
    while (cur && cur->next)
    {
        if (pre->next->val != cur->next->val)
        {
            pre = pre->next;
            cur = cur->next;
        }
        else
        {
            while (cur && cur->next && pre->next->val == cur->next->val)
                cur = cur->next;
            pre->next = cur->next;
            cur = cur->next;
        }
    }
    return phead.next;
}