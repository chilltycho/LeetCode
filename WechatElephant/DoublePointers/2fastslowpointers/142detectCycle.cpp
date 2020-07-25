/*找出链表环入口
输入：3->2->0->4->2
输出：pos=1*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/*见图*/
ListNode *detectCycle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)//第一次相遇
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
    }
    return nullptr;
}