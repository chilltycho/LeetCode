/*给出完全二叉树，求出该树的节点数量。完全二叉树除最底层节点可能没填满外，
每层节点达到最大值，最下面一层节点集中在该层最左边若干位置。*/
#include "TreeNode.h"
/*若根节点左子树深度等于右子树深度，左子树满
若根节点左子树深度大于右子树，右子树为满二叉*/
int depth(TreeNode *root) {
  int dep = 0;
  while (root) {
    root = root->left;
    dep++;
  }
  return dep;
}

// O(logn * logn)
int countNodes(TreeNode *root) {
  if (root == nullptr)
    return 0;
  int left_dep = depth(root->left);
  int right_dep = depth(root->right);
  if (left_dep == right_dep) //左子树满。只需计算一边
    return countNodes(root->right) + (1 << left_dep);
  else //左子树深度大于右子树，右子树满
    return countNodes(root->left) + (1 << right_dep);
}

// O(n)
int countNodes(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return countNodes(root->left) + countNodes(root->right) + 1;
}

// 二分查找，总结点数=倒数第二层以上节点数+最后一层节点数
