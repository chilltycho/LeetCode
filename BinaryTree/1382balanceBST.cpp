/*给定二叉搜索树,返回平衡后二叉搜索树,每个节点两棵子树高度差不超过1*/
#include "TreeNode.h"
using namespace std;
void inOrder(TreeNode *node, vector<int> &res) {
  if (node == nullptr)
    return;
  inOrder(node->left, res);
  res.push_back(node->val); //中序保证数组升序
  inOrder(node->right, res);
}

TreeNode *buildBalanceBST(vector<int> &res, int left, int right) {
  if (left > right) //列表为空
    return nullptr;
  if (left == right) //列表长度为1,构成叶子节点
    return new TreeNode(res[left]);
  int mid = left + (right - left) / 2; //每次选取中间节点作为根节点
  auto root = new TreeNode(res[mid]);
  auto leftSubTree = buildBalanceBST(res, left, mid - 1);
  auto rightSubTree = buildBalanceBST(res, mid + 1, right);
  root->left = leftSubTree;
  root->right = rightSubTree;
  return root;
}

TreeNode *balanceBST(TreeNode *root) {
  vector<int> res;
  inOrder(root, res);
  int len = res.size();
  return buildBalanceBST(res, 0, len - 1);
}

int main() {
  vector<int> ori{1, -1, 2, -1, 3, -1, 4, -1, -1};
  auto root = vecToTree(ori);
  auto res = balanceBST(root);
  preprint(res); //结果不唯一
}

