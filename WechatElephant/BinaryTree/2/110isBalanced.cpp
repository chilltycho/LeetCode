/*给定一个二叉树，判断它是否为高度平衡的二叉树。左右两个子树的高度差的绝对值不超过1*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool balanced;

int dfs(TreeNode *root)//求根节点到叶子深度
{
    if (root == nullptr)
        return 0;
    int lefth = dfs(root->left);
    int righth = dfs(root->right);
    if (abs(lefth - righth) > 1)
        balanced = false;
    return 1 + max(lefth, righth);
}

bool isBalanced(TreeNode *root)
{
    balanced=true;
    dfs(root);
    return balanced;
}

int main()
{
    TreeNode r(3);
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);

    r.left = &n9;
    r.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    cout << isBalanced(&r);
}