#include "../utl.h"
#include <stack>
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
ListNode *reverse(ListNode *root)
{
    if (!root || !root->next)
        return root;
    auto res = reverse(root->next);
    root->next->next = root;
    root->next = nullptr;
    return res;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *res = new ListNode(-1);
    auto cur = res;
    int carry = 0;
    while (l1 || l2)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry > 0)
        cur->next = new ListNode(carry);
    return reverse(res->next);
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
    vector<int> v1{7, 2, 4, 3};
    auto r1 = createLinkedList(v1);
    vector<int> v2{5, 6, 4};
    auto r2 = createLinkedList(v2);
    auto res = addTwoNumbers(r1, r2);
    printLinkeList(res);
}