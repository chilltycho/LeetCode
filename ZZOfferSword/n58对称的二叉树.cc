#include "TreeNode.h"
bool dfs(TreeNode *l, TreeNode *r)
{
    if (l == nullptr && r == nullptr)
        return true;
    if (l == nullptr || r == nullptr)
        return false;
    if (l->val != r->val)
        return false;
    else
        return dfs(l->left, r->right) && dfs(l->right, r->left);
}
bool isSymmetrical(TreeNode *pRoot)
{
    if (!pRoot)
        return true;
    return dfs(pRoot->left, pRoot->right);
}