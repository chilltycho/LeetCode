//给定二叉树，找出其最小深度，最小深度是从根节点到最近叶子节点的最短路径上的节点数量
#include "../TreeNode.h"
#include <cassert>
#include <queue>
using namespace std;

//层序
int minDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;
  queue<TreeNode *> mq;
  int res = 1;
  mq.push(root);
  while (!mq.empty()) {
    int size = mq.size();
    for (int i = 0; i < size; i++) {
      auto node = mq.front();
      mq.pop();
      if (node->left == nullptr && node->right == nullptr) {
        return res;
      }
      if (node->left != nullptr)
        mq.push(node->left);
      if (node->right != nullptr)
        mq.push(node->right);
    }
    res++; //注意深度增加位置。
  }
  return -1;
}

int minDepth_1(TreeNode *root) {
  if (root == nullptr)
    return 0;
  if (root->left == nullptr && root->right == nullptr) // 叶子节点
    return 1;
  // 如果左或右有一个为空，返回较大的
  int l = minDepth_1(root->left);
  int r = minDepth_1(root->right);
  // 有一个为空时，返回不为空的孩子的深度
  if (!root->left || !root->right)
    return l + r + 1;   // l，r必然一个为0
  return min(l, r) + 1; // 都不为空
}

int dfs1(TreeNode *node) {
  // 根为null，返回0
  if (!node) {
    return 0;
  }
  // 叶节点，返回1
  if (!node->left && !node->right) {
    return 1;
  }
  // 左节点为空，返回1+右节点的
  if (!node->left) {
    return 1 + dfs1(node->right);
  }
  // 右节点为空，返回1+左节点的
  if (!node->right) {
    return 1 + dfs1(node->left);
  }
  return 1 + min(dfs1(node->left), dfs1(node->right));
}

int main() {
  vector<int> vi{3, 9, 20, 15, -1, -1, 7};
  auto t1 = vecToTree(vi);
  cout << minDepth(t1) << endl;
  assert(2 == minDepth(t1));
}
