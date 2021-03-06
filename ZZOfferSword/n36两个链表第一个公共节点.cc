struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    auto h1 = headA;
    auto h2 = headB;
    while (h1 != h2)
    {
        h1 = (h1 == nullptr ? headB : h1->next);
        h2 = (h2 == nullptr ? headA : h2->next);
    }
    return h1;
}