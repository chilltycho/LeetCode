#include "TreeNode.h"
bool dfs(TreeNode *l, TreeNode *r) {
  if (r == nullptr)
    return true;
  if (l == nullptr || l->val != r->val)
    return false;
  return dfs(l->left, r->left) && dfs(l->right, r->right);
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
  if (pRoot1 == nullptr || pRoot2 == nullptr)
    return false;
  return dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) ||
         HasSubtree(pRoot1->right, pRoot2);
}
