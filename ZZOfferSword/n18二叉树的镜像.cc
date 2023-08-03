#include "TreeNode.h"
#include <vector>
using std::swap;
TreeNode *Mirror(TreeNode *pRoot) {
  // write code here
  if (pRoot == nullptr)
    return nullptr;
  swap(pRoot->left, pRoot->right);
  Mirror(pRoot->left);
  Mirror(pRoot->right);
  return pRoot;
}
