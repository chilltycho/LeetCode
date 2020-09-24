#include "utl.h"
//给定单链表，将第奇数个节点和第偶数个节点分别排在一起
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto odd = head;
    auto evenh = head->next;
    auto even = evenh;
    while (odd != nullptr && odd->next != nullptr && odd->next->next != nullptr)
    {
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenh;
    return head;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto head = createLinkedList(vi);
    auto res = oddEvenList(head);
    printLinkeList(res); //1,3,5,2,4

    vector<int> vi1{2, 1, 3, 5, 6, 4, 7};
    auto head1 = createLinkedList(vi1);
    auto res1 = oddEvenList(head1);
    printLinkeList(res1); //2,3,6,7,1,5,4
}