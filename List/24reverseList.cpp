struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *reverseList(ListNode *head)
{
    ListNode *cur = nullptr;
    ListNode *pre = head;
    while (pre != nullptr)
    {
        ListNode *t = pre->next;
        pre->next = cur;
        cur = pre;
        pre = t;
    }
    return cur;
}

ListNode *reverseList_re(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *ret = reverseList_re(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ret;
}
