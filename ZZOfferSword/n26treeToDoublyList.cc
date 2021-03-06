/*输入一颗二叉树，将其转换一个排序的循环双向链表。要求不能创建任何新节点，只能调节树中节点转向*/
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node() {}
    Node(int _val)
    {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};
Node *pre, *head;
void dfs(Node *cur)
{
    if (cur == nullptr)
        return;
    dfs(cur->left);
    if (pre != nullptr) //不是头节点
        pre->right = cur;
    else
        head = cur;
    cur->left = pre;
    pre = cur; //保持尾节点
    dfs(cur->right);
}
Node *treeToDoublyList(Node *root)
{
    if (root == nullptr)
        return nullptr;
    pre = nullptr;
    head = nullptr;

    dfs(root);
    head->left = pre;  //head前面是尾
    pre->right = head; //尾的后面是头
    return head;
}

void print(Node *r)
{
    if (r->right == head)
    {
        cout << r->val << ' ';
        return;
    }
    cout << r->val << ' ';
    print(r->right);
}
int main()
{
    Node r(4);
    Node n2(2);
    Node n5(5);
    Node n1(1);
    Node n3(3);

    r.left = &n2;
    r.right = &n5;
    n2.left = &n1;
    n2.right = &n3;

    auto res = treeToDoublyList(&r);
    print(res);
}