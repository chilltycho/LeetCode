//将链表每个节点向右移动k个位置,k为非负数
#include "utl.h"
#include <cassert>
using namespace std;
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;
    ListNode *p = head;
    int len = 1;
    while (p->next != nullptr)
    {
        p = p->next;
        len++;
    }
    p->next = head;//形成环
    
    k %= len;
    p=head;
    while(len!=k+1)//找断点
    {
        --len;
        p=p->next;
    }

    head = p->next;//新头
    p->next = nullptr;
    return head;
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