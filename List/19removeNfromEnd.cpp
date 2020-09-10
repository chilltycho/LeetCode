struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) //删除倒数第n个节点 ，若长度为L，则删除第L-n+1
{
    ListNode dummy(0);//保障唯一元素情况
    dummy.next = head;
    int length = 0;
    ListNode *first = head;
    while (first != nullptr)
    {
        length++;
        first = first->next;
    }
    length -= n;
    first = &dummy;
    while (length > 0)
    {
        length--;
        first = first->next;
    }
    first->next = first->next->next;
    return dummy.next;
}

ListNode *remove_1(ListNode* head,int n)//双指针，保持两指针间隔为n，则一个到底后，删除另外一个即可
{
    ListNode dummy(0);
    dummy.next=head;
    ListNode* first=&dummy;
    ListNode* second=&dummy;
    for(int i=1;i<=n+1;i++)
    {
        first=first->next;
    }
    while(first!=nullptr)
    {
        first=first->next;
        second=second->next;
    }
    second->next=second->next->next;
    return dummy.next;
}