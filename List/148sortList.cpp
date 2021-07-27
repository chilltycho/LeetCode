/*在O(NlogN)时间复杂度和常数空间复杂度下，对链表进行排序*/
#include "utl.h"
using namespace std;
/*归并排序：
对数组：
划分：将数组平分为左右两半，O(1)时间
递归：对左右两半的数组分别递归排序，每一半是n/2的规模
合并：将左右已排序的数组合并为一个，O(n)的时间
对链表：
划分：不能随机访问链表中点，需遍历一次，O(n)的时间
递归：与数组排序一样
合并：只需要用顺序遍历，O(n)*/
//1.链表切分：寻找链表中点，删除中点左侧指针，将链表断开
ListNode *findMid(ListNode *head)
{
    auto s = head, f = head;
    ListNode *pre = nullptr;
    while (f && f->next)
    {
        pre = s;
        s = s->next;
        f = f->next->next;
    }
    pre->next = nullptr;
    return s;
}
ListNode *merge2Lists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = merge2Lists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge2Lists(l1, l2->next);
        return l2;
    }
}
ListNode *mergeSort(ListNode *head)
{
    if (!head || !(head->next))
        return head;
    auto m = findMid(head);
    auto l1 = mergeSort(head);
    auto l2 = mergeSort(m);
    return merge2Lists(l1, l2);
}

ListNode *sortList(ListNode *head)
{
    return mergeSort(head);
}

int main()
{
    vector<int> vi{5,3,4,2,1};
    auto root=createLinkedList(vi);
    auto res = sortList(root);
    printLinkeList(res);
}