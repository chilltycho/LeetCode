struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;
    else if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode *mergeTwoLists_1(ListNode *l1, ListNode *l2)
{
    ListNode *prehead = new ListNode(-1);
    ListNode *prev = prehead;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == nullptr ? l2 : l1;
    return prehead->next;
}