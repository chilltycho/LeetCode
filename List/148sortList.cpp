/*在O(NlogN)时间复杂度和常数空间复杂度下，对链表进行排序*/
#include"utl.h"
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
ListNode *split(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    return slow;
}

ListNode *head, *tail;
void append(ListNode *node)
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

ListNode *merge_1(ListNode *left, ListNode *right)
{
    head = nullptr;
    tail = nullptr;
    ListNode *q1 = left;
    ListNode *q2 = right;
    while (q1 != nullptr || q2 != nullptr)
    {
        if (q1 == nullptr)
        {
            append(q2);
            q2 = q2->next;
        }
        else if (q2 == nullptr)
        {
            append(q1);
            q1 = q1->next;
        }
        else if (q1->val < q2->val)
        {
            append(q1);
            q1 = q1->next;
        }
        else
        {
            append(q2);
            q2 = q2->next;
        }
    }
    return head;
}

ListNode *sortList_1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *mid = split(head);
    ListNode *left = sortList_1(head);
    ListNode *right = sortList_1(mid);
    return merge_1(left, right);
}

//由于只能常数空间复杂度，故不能递归
//自顶向上归并排序：先两两归并，再四四归并...
ListNode *cut(ListNode *head, int n) //将链表l切掉前n个节点，返回后半部分链表头
{
    auto p = head;
    while (--n && p)
        p = p->next;
    if (!p)
        return nullptr;
    auto ne = p->next;
    p->next = nullptr;
    return ne;
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode dummyHead(0);
    auto p = &dummyHead;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }
    p->next = l1 ? l1 : l2;
    return dummyHead.next;
}

ListNode *sortList(ListNode *head)
{
    ListNode dummyHead(0);
    dummyHead.next = head;
    auto p = head;
    int length = 0;
    while (p)
    {
        ++length;
        p = p->next;
    } //计算链表长度

    for (int size = 1; size < length; size <<= 1) //有哑节点，故从1开始
    {
        auto cur = dummyHead.next;
        auto tail = &dummyHead;

        while (cur)
        {
            auto left = cur;
            auto right = cut(left, size);
            cur = cut(right, size);
            tail->next = merge(left, right);
            while (tail->next)
                tail = tail->next;
        }
    }
    return dummyHead.next;
}

void print(ListNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << ' ';
        print(root->next);
    }
}

int main()
{
    ListNode root(5);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    root.next = &n2;
    n2.next = &n3;
    n3.next = &n1;
    n1.next = &n4;

    auto res = sortList_1(&root);
    print(res);
}