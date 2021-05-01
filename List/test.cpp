#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) // 只有一个节点或空，返回
        return head;
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    auto newh = swapPairs(&n1);
    auto ite = newh;
    while (ite)
    {
        cout << ite->val << ' ';
        ite = ite->next;
    }
}