/*给定两二叉树,将一个覆盖到另一个上,重叠的将值相加*/
#include "TreeNode.h"
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
  if (t1 == nullptr)
    return t2;
  if (t2 == nullptr)
    return t1;
  t1->val += t2->val;
  t1->left = mergeTrees(t1->left, t2->left);
  t1->right = mergeTrees(t1->right, t2->right);
  return t1;
}

int main() {
  vector<int> v1{1, 3, 2, 5};
  vector<int> v2{2, 1, 3, -1, 4, -1, 7};
  auto t1 = vecToTree(v1);
  auto t2 = vecToTree(v2);
  auto res = mergeTrees(t1, t2);
  preprint(res);
}