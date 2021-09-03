#include "utl.h"
using namespace std;
ListNode *reverse(ListNode *a, ListNode *b)
{
    if (a == b || b == nullptr)
        return a;
    auto pre = b, cur = a;
    while (cur != b)
    {
        auto nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    --left;
    auto cura = head, curb = head;
    ListNode *pre = nullptr;
    while (left)
    {
        pre = cura;
        cura = cura->next;
        --left;
    }
    while (right)
    {
        curb = curb->next;
        --right;
    }
    if (pre == nullptr)
    {
        reverse(head, nullptr);
    }
    else
    {
        pre->next = reverse(cura, curb);
    }
    return head;
}
int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto head = createLinkedList(vi);
    reverseBetween(head, 1, 1);
    printLinkeList(head);
}