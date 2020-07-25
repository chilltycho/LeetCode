#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *last = nullptr;

void flatten(TreeNode *root)//将二叉树变为链表
{
    if (root == nullptr)
        return;
    flatten(root->left);//将根节点左子树变为链表
    flatten(root->right);//将根节点右子树变为链表
    auto temp=root->right;
    root->right=root->left;
    root->left=nullptr;
    while(root->right!=nullptr)
        root=root->right;
    root->right=temp;
}

void printlist(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << ' ';
    printlist(root->right);
}
int main()
{
    TreeNode r(1);
    TreeNode n2(2);
    TreeNode n5(5);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n6(6);

    r.left = &n2;
    r.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    flatten(&r);
    printlist(&r);
}