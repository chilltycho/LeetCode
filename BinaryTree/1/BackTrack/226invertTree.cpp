//翻转二叉树
#include "../../TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode *invertTree(TreeNode *root) {
  if (root == nullptr)
    return root;
  swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

TreeNode *invertTree_bfs(TreeNode *root) {
  if (root == nullptr)
    return nullptr;
  queue<TreeNode *> mq;
  mq.push(root);
  while (!mq.empty()) {
    auto tmp = mq.front();
    mq.pop();
    auto tl = tmp->left;
    tmp->left = tmp->right;
    tmp->right = tl;
    if (tmp->left != nullptr)
      mq.push(tmp->left);
    if (tmp->right != nullptr)
      mq.push(tmp->right);
  }
  return root;
}

int main() {
  vector<int> vi{4, 2, 7, 1, 3, 6, 9};
  auto t = vecToTree(vi);
  auto res = invertTree(t);
  preprint(res);
}