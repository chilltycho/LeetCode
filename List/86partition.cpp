//给定链表和特定值x，对链表分割，使所有小于x的节点都在大于或等于x的节点之前,不改变相对顺序
#include"utl.h"

ListNode* partition(ListNode* head,int x)
{
    if(head==nullptr||head->next==nullptr)
        return head;
    ListNode *before_head=new ListNode(0);
    ListNode* before=before_head;
    ListNode *after_head=new ListNode(0);
    ListNode* after=after_head;
    while(head!=nullptr)
    {
        if(head->val<x)
        {
            before->next=head;
            before=before->next;
        }
        else
        {
            after->next=head;
            after=after->next;
        }
        head=head->next;
    }
    before->next=after_head->next;
    after->next=nullptr;
    return before_head->next;
}

int main()
{
    vector<int> vi{1,4,3,2,5,2};
    auto head=createLinkedList(vi);
    auto res=partition(head,3);
    printLinkeList(res);
}