//给定二叉树，找出其最大深度，最大深度是从根节点到最近叶子节点的最长路径上的节点数量
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode *root) //解决的是根节点到最远叶子节点的最长路径
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr)
        return 1 + maxDepth(root->right);
    if (root->right == nullptr)
        return 1 + maxDepth(root->left);
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);

    TreeNode p(3);
    p.left = &n9;
    p.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    cout << maxDepth(&p);
}