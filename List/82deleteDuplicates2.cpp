#include "utl.h"
//已经排好序的数组，删除所有含重复数字的节点
ListNode *deleteDuplicates_1(ListNode *head)
{
    if(head==nullptr||head->next==nullptr)
        return head;
    if(head->val==head->next->val)//删除头部重复节点
    {
        while(head!=nullptr&&head->next!=nullptr&&head->val==head->next->val)
            head=head->next;
        return deleteDuplicates_1(head->next);
    }
    else
    {
        head->next=deleteDuplicates_1(head->next);
        return head;
    }
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