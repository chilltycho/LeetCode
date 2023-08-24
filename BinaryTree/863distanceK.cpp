// 二叉树中所有距离为K的节点
#include "TreeNode.h"
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

void printvec(vector<int> &nums) {
  for (auto c : nums) {
    cout << c << ' ';
  }
  cout << endl;
}

unordered_map<int, TreeNode *> parents;
vector<int> res;

void findParents(TreeNode *node) {
  if (!node) {
    return;
  }
  if (node->left) {
    parents[node->left->val] = node;
    findParents(node->left);
  }
  if (node->right) {
    parents[node->right->val] = node;
    findParents(node->right);
  }
}

void dfs(TreeNode *node, TreeNode *from, int depth, int k) {
  if (!node) {
    return;
  }
  if (node)
    cout << " node val " << node->val << endl;
  if (from)
    cout << " from val " << from->val << endl;
  if (depth == k) {
    res.push_back(node->val);
    return;
  }
  // 从target向下去找, from避免向下递归时不会向上，向上递归时不向下
  if (node->left != from) {
    dfs(node->left, node, depth + 1, k);
  }
  if (node->right != from) {
    dfs(node->right, node, depth + 1, k);
  }
  // 从target向上去找
  if (parents[node->val] != from) {
    dfs(parents[node->val], node, depth + 1, k);
  }
}

// 距离目标节点target为k的节点列表，节点值各不相同
vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
  findParents(root);
  dfs(target, nullptr, 0, k);

  return res;
}

int main() {
  vector<int> nums{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
  auto root = vecToTree(nums);
  // 7,4,1
  auto res = distanceK(root, root->left, 2);
  for (auto c : res) {
    cout << c << ' ';
  }
  cout << endl;
}
