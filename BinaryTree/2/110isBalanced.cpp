/*给定一个二叉树，判断它是否为高度平衡的二叉树。左右两个子树的高度差的绝对值不超过1*/
#include "../TreeNode.h"
#include <cassert>
using namespace std;

bool balanced = true;

int dfs(TreeNode *root) //求根节点到叶子深度
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
    dfs(root);
    return balanced;
}
//时间O(N)最差需遍历所有节点,空间O(N)
//当root左/右子树深度差<=1，返回最大深度。当>1返回-1,代表不是平衡树
int dfs_down2head(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = dfs_down2head(root->left);
    if (left == -1)
        return -1;
    int right = dfs_down2head(root->right);
    if (right == -1)
        return -1;
    return abs(left - right) < 2 ? max(left, right) + 1 : -1;
}

bool isBalanced_down2head(TreeNode *root)
{
    return dfs_down2head(root) != -1;
}

int depth_head2down(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(depth_head2down(root->left),
               depth_head2down(root->right)) +
           1;
}

//时间O(NlogN)空间O(N)，计算每个节点左右子树深度
bool isBalanced_head2down(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return abs(depth_head2down(root->left) - depth_head2down(root->right)) <= 1 && isBalanced_head2down(root->right) && isBalanced_head2down(root->left);
}
int main()
{
    vector<int> vi{3, 9, 20, -1, -1, 15, 7};
    auto t1 = vecToTree(vi);
    assert(isBalanced(t1));
}