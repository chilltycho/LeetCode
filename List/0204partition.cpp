//给定链表，使得所有小于x的节点排在大于或等于x的节点之前
#include"utl.h"

ListNode* partition(ListNode* head,int x)
{
    auto p=head,q=head;
    while(q)
    {
        if(q->val<x)
        {
            q->val=p->val;
            p->val=q->val;
            p=p->next;
        }
        q=q->next;
    }
    return head;
}

int main()
{
    vector<int> vi{3,3,2,2,1,4};
    auto head=createLinkedList(vi);
    auto res =partition(head,2);
    printLinkeList(res);
}