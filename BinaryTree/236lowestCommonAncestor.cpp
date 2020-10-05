/*给定二叉树,找到该树中两指定节点最近公共祖先.
root是p,q的最近公共祖先的情况:
1.p和q在root的子树中,且分裂在root的异侧
2.p=root,q在root的左或右子树中
3.q=root,p在root的左或右子树中*/
#include "TreeNode.h"
using namespace std;
/*
终止条件:
1.当越过叶节点,直接返回null
2.当root等于p,q直接返回root
递归:
1.开启递归左子节点,返回值记为left
2.开启递归右子节点,返回值记为right
返回值:
1.left和right同时为空,root的左右子树中都不包含p,q返回null
2.left和right同时不为空,返回root
3.left为空,right不为空,直接返回right
4.left不为空,right不为空,返回left
*/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || p == root || q == root)
    {
        return root;
    }
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr)
        return root;
    if (left == nullptr)
        return right;
    return left;
}

int main()
{
    vector<int> nums{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode node[9];
    for (int i = 0; i < 9; i++)
        node[i].val = i;
    node[3].left = &node[5];
    node[3].right = &node[1];
    node[5].left = &node[6];
    node[5].right = &node[2];
    node[2].left = &node[7];
    node[2].right = &node[4];
    node[1].left = &node[0];
    node[1].right = &node[8];
    auto res = lowestCommonAncestor(&node[3], &node[5], &node[1]);
    cout << res->val << endl;
}