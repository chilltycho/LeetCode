#include "utl.h"

bool isPalindrome(ListNode *head) //1->2->2->1
{
    vector<int> vals;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        vals.push_back(cur->val);
        cur = cur->next;
    }
    int front = 0, back = vals.size() - 1;
    while (front < back)
    {
        if (vals[front] != vals[back])
            return false;
        front++;
        back--;
    }
    return true;
}

bool isPalindrome_1(ListNode *head) //从中间位置反转列表。
{
    if (head == nullptr || head->next == nullptr)
        return true;
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    } //此时slow指向中心节点

    ListNode *curNode = slow, *nextNode = slow->next;
    while (nextNode != nullptr) //反转链表
    {
        ListNode *tmp = nextNode->next;
        nextNode->next = curNode;
        curNode = nextNode;
        nextNode = tmp;
    }
    slow->next = nullptr; //中心节点指向nullptr

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
    vector<int> vi{1, 2, 2, 1};
    auto head = createLinkedList(vi);
    cout << isPalindrome(head);
}