/*给定带头节点head的非空单链表，返回链表中间节点。若有两个中间节点，返回第二个中间节点*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *middleNode(ListNode *head)
{
    auto slow = head;
    auto fast = head;
    while (fast != nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    ListNode root(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    root.next = &n2;
    n2.next = &n3;

    auto res = middleNode(&root);
    cout << res->val;
}