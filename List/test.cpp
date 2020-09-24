#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void insert(ListNode **linkp, int new_value)
{
    ListNode *current;
    ListNode *newnode;
    while ((current = *linkp) != nullptr) //从小到大排列
    {
        linkp = &(current->next); //current中next的地址
        //*linkp=(current->next);//是错误写法，此时根节点会变
    }
    newnode = (ListNode *)malloc(sizeof(ListNode));
    if (newnode == nullptr)
    {
        cerr << "error in insert no memory";
        exit(-1);
    }
    newnode->next = current;
    newnode->val = new_value;
    *linkp = newnode;
    //cout<<(*linkp)->val<<' ';
}

ListNode *removeNfromEnd(ListNode *head, int n) //保证n有效
{
    ListNode dummy(0); //保障唯一元素情况
    dummy.next = head;
    int length = 0;
    ListNode *first = head;
    while (first != nullptr)
    {
        length++;
        first = first->next;
    }
    length -= n;
    first = &dummy;
    while (length > 0)
    {
        length--;
        first = first->next;
    }
    first->next = first->next->next;
    return dummy.next;
}

void printlist(ListNode *root)
{
    while (root != nullptr)
    {
        cout << root->val << ' ';
        root = root->next;
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr||head->next==nullptr)
        return head;
    ListNode *slow = nullptr;
    ListNode *fast = head;
    while (fast!= nullptr)
    {
        auto temp = fast->next;
        fast->next = slow;
        slow=fast;
        fast = temp;
    }
    return slow;
}

bool isPalindrome_1(ListNode *head)//从中间位置反转列表。
{
    if (head==nullptr || head->next==nullptr)
        return true;
    ListNode *slow = head, *fast = head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }//此时slow指向中心节点

    ListNode *curNode = slow, *nextNode = slow->next;
    while (nextNode!=nullptr)//反转链表
    {
        ListNode *tmp = nextNode->next;
        nextNode->next = curNode;
        curNode = nextNode;
        nextNode = tmp;
    }
    slow->next = nullptr;//中心节点指向nullptr
    
    while (head && curNode)
    {
        if (head->val != curNode->val)
            return false;
        head = head->next;
        curNode = curNode->next;
    }
    return true;
}

int main()
{
    ListNode *proot = nullptr; //根指针，没有保存值，由于是nullptr，故没next成员
    //proot->next=nullptr;
    //proot->value=-999;
    for (int i = 0; i < 2; i++)
        insert(&proot, i);

}