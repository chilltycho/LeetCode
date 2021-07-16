#include "utl.h"
//已排序链表，删除重复元素，使每个元素只出现一次
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto cur = head->next;
    auto pre = head;
    while (cur)
    {
        if (pre->val == cur->val)
        {
            while (cur && pre->val == cur->val)
            {
                cur = cur->next;
            }
            pre->next = cur;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    vector<int> vi{1, 1, 2};
    auto head = createLinkedList(vi);
    auto res = deleteDuplicates_re(head);
    printLinkeList(res);
}