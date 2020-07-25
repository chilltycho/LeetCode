#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//删除链表中所有等于val的元素，可能包含相同val
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        if (curr->val == val) //头节点情况
        {
            if (prev == nullptr)
            {
                head = curr->next;
                prev=nullptr;//删除头节点后，prev仍需指向null，考虑[1,1]
                curr=curr->next;
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
    ListNode head(1);
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    head.next = &l1;
    //print(&head);

    ListNode *newlist = removeElements(&head,1);
    print(newlist);
}