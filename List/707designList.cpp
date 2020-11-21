#include <iostream>
using namespace std;
class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int v) : val(v), next(nullptr) {}
    };
    int size;
    ListNode *head;
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        size = 0;
        head = nullptr;
    }
    void print()
    {
        auto ite = head;
        while (ite != nullptr)
        {
            cout << ite->val << ' ';
            ite = ite->next;
        }
        cout << "nullptr" << endl;
    }
    void deletelist()
    {
        if (head == nullptr)
            free(head);
        ListNode *cur = head;
        ListNode *nex = nullptr;
        while (cur != nullptr)
        {
            nex = cur->next;
            free(cur);
            cur = nex;
        }
        head = nullptr;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (size <= index)
            return -1;
        auto ite = head;
        while (index--)
            ite = ite->next;
        return ite->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (head == nullptr)
        {
            head = new ListNode(val);
            size++;
            return;
        }
        auto newH = new ListNode(val);
        newH->next = head;
        head = newH;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (head == nullptr)
        {
            head = new ListNode(val);
            size++;
            return;
        }
        auto ite = head;
        while (ite->next != nullptr)
            ite = ite->next;
        ite->next = new ListNode(val);
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index <= 0)
        {
            addAtHead(val);
            return;
        }
        auto ite = head;
        while (--index)
        {
            ite = ite->next;
        }
        auto temp = ite->next;
        ite->next = new ListNode(val);
        ite->next->next = temp;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        if (index == 0)
        {
            auto temp = head;
            head = head->next;
            free(temp);
            size--;
            return;
        }
        else
        {
            auto ite = head;
            while (--index)
            {
                ite = ite->next;
            }
            auto temp = ite->next;
            ite->next = ite->next->next;
            free(temp);
            size--;
        }
    }
};

int main()
{
#if 0
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2); //链表变为1-> 2-> 3
    linkedList.get(1);           //返回2
    linkedList.deleteAtIndex(1); //现在链表是1-> 3
    linkedList.print();
    linkedList.get(1); //返回3
    linkedList.deletelist();
#endif
#if 1
    MyLinkedList l1;
    l1.addAtHead(2);
    l1.deleteAtIndex(1);
    l1.addAtHead(2);
    l1.addAtHead(7);
    l1.addAtHead(3);
    l1.addAtHead(2);
    l1.addAtHead(5);
    l1.addAtTail(5);
    l1.print();
    l1.get(5);
    l1.deleteAtIndex(6);
    l1.deleteAtIndex(4);
#endif
}