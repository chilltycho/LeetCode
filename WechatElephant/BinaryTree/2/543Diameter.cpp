/*给定二叉树，计算直径长度，是两个节点路径长度中的最大值，可能也可能不穿过根节点*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
二叉树最长路径=max(左子树最长路径，右子树最长路径，左子树深度+右子树深度）*/
int diameter = 0;

int dfs(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode *root)
{
    dfs(root);
    return diameter;
}

int main()
{
    TreeNode r(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    r.left=&n2;
    r.right=&n3;
    n2.left=&n4;
    n2.right=&n5;

    cout<<diameterOfBinaryTree(&r);
}