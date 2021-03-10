//翻转整个链表
#include "utl.h"
using namespace std;

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
/*
问题：单向链表反转
令F(node)为问题，反转以node为头结点的单向链表。
考虑F(n)和F(n-1)的关系，n代表以node为头结点的单向链表，n-1为node->next为头结点的链表。
令F(node->next)为问题：反转以node->next为头结点的单向链表。
考虑F(node)和F(node->next)的关系。
1->2->3
假设F(node=2)已解决，如何解决F(node=1):
需反转node=2和node=1，即node->next(2)->next=node(1)同时，node(1)->next=nullptr;
所以该问题为：F(node=1) = F(node=2) + 反转node=2和node=1
*/
ListNode *reverseList_re(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) // 只有一个节点或空
        return head;
    ListNode *ret = reverseList_re(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ret;
}

ListNode *reverseList_re1(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *cur = head;
    while (head->next != nullptr)
    {
        ListNode *t = head->next->next;
        head->next->next = cur;
        cur = head->next;
        head->next = t;
    }
    return cur;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto root = createLinkedList(vi);
    printLinkeList(reverseList_re1(root));
}


