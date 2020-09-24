#include "utl.h"
//已排序链表，删除重复元素，使每个元素只出现一次
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto cur = head;
    while (cur->next != nullptr)
    {
        if (cur->val == cur->next->val)
        {
            auto temp = cur->next;
            cur->next = temp->next;
            temp->next = nullptr;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    vector<int> vi{1, 1, 2};
    auto head = createLinkedList(vi);
    auto res = deleteDuplicates(head);
    printLinkeList(res);
}