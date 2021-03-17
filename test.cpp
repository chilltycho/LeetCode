#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 3) : val(x), next(nullptr) {}
};

ListNode *reverse(ListNode *head, int &sz)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto newh = reverse(head->next, ++sz);
    head->next->next = head;
    head->next = nullptr;
    return newh;
}
// s1>s2
void addList(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    while (l2)
    {
        int sum = l1->val + l2->val + carry;
        l1->val = (sum) % 10;
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1->next)
    {
        int sum = l1->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        l1 = l1->next;
    }
    if (carry)
    {
        l1->next = new ListNode(carry);
    }
}

ListNode *addInList(ListNode *head1, ListNode *head2)
{
    // write code here
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    int sz1 = 1, sz2 = 1;
    auto new1 = reverse(head1, sz1);
    auto new2 = reverse(head2, sz2);
    if (sz1 > sz2)
    {
        addList(new1, new2);
        reverse(new1, sz1);
        return new1;
    }
    else
    {
        addList(new2, new1);
        reverse(new2, sz2);
        return new2;
    }
}
int main()
{
    ListNode a9(9);
    ListNode a3(3);
    ListNode a7(7);
    ListNode a6(6);
    ListNode a33(3);
    a9.next = &a3;
    a3.next = &a7;
    a6.next = &a33;
    auto l = addInList(&a9, &a6);
    while (l)
    {
        cout << l->val << ' ';
        l = l->next;
    }
}