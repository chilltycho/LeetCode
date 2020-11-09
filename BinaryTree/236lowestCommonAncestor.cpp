/*给定二叉树,找到该树中两指定节点最近公共祖先.
root是p,q的最近公共祖先的情况:
1.p和q在root的子树中,且分裂在root的异侧
2.p=root,q在root的左或右子树中
3.q=root,p在root的左或右子树中
对二叉树后序遍历,遇到节点p或q时返回,当p,q在root异侧时,root为最近公共祖先,向上返回root*/
#include "TreeNode.h"
using namespace std;
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    //root==p||q 返回root
    if (root == nullptr || p == root || q == root)
        return root;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    if (left != nullptr && right != nullptr)
        return root;
    return nullptr;
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