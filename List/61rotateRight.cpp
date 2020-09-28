#include "utl.h"

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;
    int size = 1;
    auto cur = head;
    while (cur != nullptr && cur->next != nullptr) //让cur到达尾节点
    {
        cur = cur->next;
        size++;
    }
    int move = k % size;
    if (move == 0)
        return head;

    ListNode *cut = head;
    for (int i = 0; i < size - move - 1; ++i)
        cut = cut->next;
    ListNode *result = cut->next; //新头节点
    cut->next = nullptr;
    cur->next = head;
    return result;
}

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    auto l1 = createLinkedList(v1);
    auto res1 = rotateRight(l1, 2);
    printLinkeList(res1); //4->5->1->2->3->null

    vector<int> v2{0, 1, 2};
    auto l2 = createLinkedList(v2);
    auto res2 = rotateRight(l2, 4);
    printLinkeList(res2); //2->0->1->null
}