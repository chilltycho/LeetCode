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
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;
    unordered_map<Node *, Node *> match;
    Node *pos = head;
    Node *newHead = new Node(head->val);
    Node *copy = newHead;

    while (pos) // 先顺序遍历
    {
        match[pos] = copy;
        pos = pos->next;
        if (!pos)
        {
            copy->next = nullptr;
            match[pos] = nullptr;
        }
        else
            copy->next = new Node(pos->val);
        copy = copy->next;
    }

    pos = head;
    copy = newHead;

    while (pos)
    {
        copy->random = match[pos->random];
        copy = copy->next;
        pos = pos->next;
    }
    return newHead;
}