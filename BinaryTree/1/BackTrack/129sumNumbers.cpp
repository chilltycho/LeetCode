/*给定二叉树，每个节点存放0-9，从根到叶子节点路径1->2->3代表123，计算从根到叶子节点生成
所有数字之和*/
#include "../../TreeNode.h"
#include <queue>
using namespace std;
int res = 0, path = 0;
void helper(TreeNode *root) {
  // dfs
  if (root == nullptr)
    return;
  int tmp = path;
  path = path * 10 + root->val;
  if (root->left == nullptr && root->right == nullptr)
    res += path;
  helper(root->left);
  helper(root->right);
  path = tmp; // 回溯
}

int sumNumbers(TreeNode *root) {
  helper(root);
  return res;
}
// bfs
int sumNumbers_1(TreeNode *root) {
  if (root == nullptr)
    return 0;
  vector<int> nums;
  queue<TreeNode *> mqnode;
  queue<int> mqnums;
  mqnums.push(root->val);
  mqnode.push(root);
  while (!mqnode.empty()) {
    auto node = mqnode.front();
    int temp = mqnums.front();
    mqnode.pop();
    mqnums.pop();
    if (node->left == nullptr && node->right == nullptr)
      nums.push_back(temp);
    if (node->left != nullptr) {
      mqnums.push(temp * 10 + node->left->val);
      mqnode.push(node->left);
    }
    if (node->right != nullptr) {
      mqnums.push(temp * 10 + node->right->val);
      mqnode.push(node->right);
    }
  }
  int sum = 0;
  for (auto c : nums)
    sum += c;
  return sum;
}

int main() {
  vector<int> vi{4, 9, 0, 5, 1};
  auto t1 = vecToTree(vi);
  cout << sumNumbers(t1);
}