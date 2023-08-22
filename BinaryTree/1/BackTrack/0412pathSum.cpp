/* 求从任意节点往下路径和等于特定值的路径数
        5
       / \
      4   8
     /   / \
    11  13  4
    / \     / \
    7  2    5   1
和为22的路径有：[5,4,11,2], [5,8,4,5], [4,11,7] 输出3
*/
#include "../../TreeNode.h"
using namespace std;
// 对每个节点作为根
int res = 0, target;

void calc(TreeNode *root, int tmpsum) {
  if (root == nullptr)
    return;
  tmpsum += root->val;
  if (tmpsum == target)
    ++res;
  calc(root->left, tmpsum);
  calc(root->right, tmpsum);
}

void dfs(TreeNode *root) {
  if (root == nullptr)
    return;
  int tmp = 0;
  calc(root, tmp);
  dfs(root->left);
  dfs(root->right);
}

int pathSum(TreeNode *root, int sum) {
  if (root == nullptr)
    return 0;
  target = sum;
  dfs(root);
  return res;
}