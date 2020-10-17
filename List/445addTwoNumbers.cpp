#include"utl.h"
#include<stack>
using namespace std;
//两非空链表代表两个非负整数，数字最高位位于链表开始位置。每个节点只存储一位数字。不能对节点反转
ListNode *addTwoNumbers_1(ListNode *l1, ListNode *l2) //考虑先读出，再用栈
{
    stack<int> s1, s2;
    while (l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    ListNode *ans = nullptr;
    while (!s1.empty() || !s2.empty() || carry != 0)
    {
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if (!s1.empty())
            s1.pop();
        if (!s2.empty())
            s2.pop();
        int cur = a + b + carry;
        carry = cur / 10;
        cur %= 10;
        auto curnode = new ListNode(cur);
        curnode->next = ans;
        ans = curnode;
    }
    return ans;
}

//数位对其后，last指向上一个计算后非9的数，
ListNode *addTwoNumbers_2(ListNode *l1, ListNode *l2)
{
    int count = 0, temp;
    ListNode *head, *last;
    for (head = l1; head; head = head->next)
        count++;
    for (head = l2; head; head = head->next)
        count--;
    if (count < 0)
        swap(l1, l2); //l1指向长链
    last = head = new ListNode(0);
    head->next = l1;
    for (int i = abs(count); i != 0; i--) //数位对齐
    {
        if (l1->val != 9)
            last = l1;
        l1 = l1->next;
    }
    while (l1)
    {
        temp = l1->val + l2->val;
        if (temp > 9)
        {
            temp -= 10;
            last->val += 1;
            last = last->next;
            while (last != l1)
            {
                last->val = 0;
                last = last->next;
            }
        }
        else if (temp != 9)
            last = l1;
        l1->val = temp;
        l1 = l1->next;
        l2 = l2->next;
    }
    return head->val == 1 ? head : head->next;
}

void print(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << ' ';
        prev = curr;
        curr = curr->next;
    }
}
int main()
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    ListNode l7(7);

    ListNode head1(7);
    head1.next = &l2;
    l2.next = &l4;
    l4.next = &l3;

    ListNode head2(5);
    head2.next = &l6;
    l5.next = &l1;

    ListNode *newlist = addTwoNumbers_2(&head1, &head2);
    print(newlist);
}