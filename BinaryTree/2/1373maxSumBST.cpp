/*给定二叉树，返回任意二叉搜索子树的最大键值和。
二叉树：任意节点左子树小于此节点键值，任意节点右子树大于此节点键值。*/
#include "../TreeNode.h"
#include <climits>
using namespace std;
/*二叉树的BST子树最大节点和=max(左子树的BST子树最大节点和，右子树..,二叉树的节点和（当前二叉树为BST）
二叉树是BST=左子树是BST，右子树是BST，根节点值>左子树最大值，根节点值<右子树最小值
二叉树最大值=max(根节点值，左子树最大值，右子树最大值）
5个子问题：1.BST子树最大节点和 2.二叉树的节点和 3.是否是BST 4.二叉树最小值 5.二叉树最大值

全局变量：最大BST子树节点和
递归函数：四个返回值*/

struct TreeInfo {
  bool isBST;
  int min;
  int max;
  int sum;
  TreeInfo(bool isBST, int min, int max, int sum) {
    this->isBST = isBST;
    this->min = min;
    this->max = max;
    this->sum = sum;
  }
};

int maxSum;
TreeInfo dfs(TreeNode *root) {
  if (root == nullptr)
    return TreeInfo(true, INT_MAX, INT_MIN, 0);
  TreeInfo le = dfs(root->left);
  TreeInfo ri = dfs(root->right);
  int sum = root->val + le.sum + ri.sum;
  if (le.isBST && ri.isBST && le.max < root->val && root->val < ri.min) {
    maxSum = max(maxSum, sum);
    int mi = min(le.min, root->val);
    int ma = max(ri.max, root->val);
    return TreeInfo(true, mi, ma, sum);
  } else
    return TreeInfo(false, INT_MAX, INT_MIN, sum);
}

int maxSumBST(TreeNode *root) {
  maxSum = 0;
  dfs(root);
  return maxSum;
}

int main() {
  vector<int> vi{1, 4, 3, 2, 4, 2, 5, -1, -1, -1, -1, -1, -1, 4, 6};
  auto root = vecToTree(vi);
  cout << maxSumBST(root);
}
