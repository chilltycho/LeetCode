/*删除列表中倒数第n个节点
1->2->3->4->5 n=2
返回 1->2->3->5*/
#include <iostream>
#include "../utl.h"
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (fast != nullptr)
    {
        prev = curr;
        curr = curr->next;
        fast = fast->next;
    }
    if (prev == nullptr) //删除头节点
    {
        auto temp = head;
        head = curr->next;
        delete temp;
        temp = nullptr;
    }
    else
    {
        auto temp = curr;
        prev->next = curr->next;
        delete temp;
        temp = nullptr;
    }
    return head;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto root = createLinkedList(vi);
    auto res = removeNthFromEnd(root, 3);
    printLinkeList(res);
    deleteLinkedList(res);
}