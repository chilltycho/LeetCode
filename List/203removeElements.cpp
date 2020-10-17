#include "utl.h"
using namespace std;

//删除链表中所有等于val的元素，可能包含相同val
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        if (curr->val == val)
        {
            if (prev == nullptr) //头节点
            {
                head = curr->next;
                prev = nullptr; //删除头节点后，prev仍需指向null，考虑[1,1]
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    vector<int> vi{1, 2, 6, 3, 4, 5, 6};
    auto head = createLinkedList(vi);
    auto res = removeElements(head, 6);
    printLinkeList(res);
}