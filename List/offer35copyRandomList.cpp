//实现复杂链表的深拷贝
#include<unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = nullptr;   //单链表形式
        random = nullptr; //随机指向一个节点或nullptr
    }
};

void copyNodes(Node *head)
{
    if (!head)
        return;
    Node *cur = head;
    while (cur)
    {
        Node *copy = new Node(cur->val);
        Node *nep = cur->next;
        cur->next = copy;
        copy->next = nep;
        cur = copy->next;
    }
}

void copyRandom(Node *head)
{
    if (!head)
        return;
    Node *pos = head;
    while (pos)
    {
        Node *copy = pos->next;
        Node *oldRandom = pos->random;
        if (oldRandom)
            copy->random = oldRandom->next;
        else
            copy->random = nullptr;
        pos = copy->next;
    }
}

Node *getCopy(Node *head)
{
    if (!head)
        return nullptr;
    Node *pos = head;
    Node *copy = pos->next;
    Node *newHead = copy;
    while (pos)
    {
        pos->next = copy->next;
        pos = pos->next;
        if (pos)
            copy->next = pos->next;
        copy = copy->next;
    }
    return newHead;
}

Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    copyNodes(head);      // 拷贝 value 和 next
    copyRandom(head);     // 拷贝 random
    return getCopy(head); // 提取出新的链表
}

Node* copyRandomList_map(Node* head)
{
    if(!head)
        return nullptr;
    unordered_map<Node*,Node*> match;
    Node* pos=head;
    Node* newHead=new Node(head->val);
    Node* copy=newHead;

    while(pos)
    {
        match[pos]=copy;
        pos=pos->next;
        if(!pos)
        {
            copy->next=nullptr;
            match[pos]=nullptr;
        }
        else
            copy->next=new Node(pos->val);
        copy=copy->next;
    }
    
    pos=head;
    copy=newHead;
    
    while(pos)
    {
        copy->random=match[pos->random];
        copy=copy->next;
        pos=pos->next;
    }
    return newHead;
}
