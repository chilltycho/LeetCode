/*输入一颗二叉树，将其转换一个排序的循环双向链表。要求不能创建任何新节点，只能调节树中节点转向*/
#include <iostream>
#include "TreeNode.h"
using namespace std;
TreeNode *pre, *head;
void dfs(TreeNode *cur)
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
TreeNode *treeToDoublyList(TreeNode *root)
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

int main()
{
    vector<int> vi{10, 6, 14, 4, 8, 12, 16};
    auto head = vecToTree(vi);
    while (head)
    {
        cout << head->val << ' ';
        head=head->right;
    }
}