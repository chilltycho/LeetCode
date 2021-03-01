#ifndef LISTNODE_H
#define LISTNODE_H
struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};
#endif