/*给定二叉树，返回所有从根节点到叶子节点的路径*/
#include "../../TreeNode.h"
#include <queue>
using namespace std;

vector<string> res;
string path;
void dfs(TreeNode *root) {
  if (root == nullptr)
    return;
  auto tmp = path;
  path += to_string(root->val);
  path += "->";
  if (root->left == nullptr && root->right == nullptr) {
    res.push_back(path);
  }
  dfs(root->left);
  dfs(root->right);
  path = tmp; //回溯
}
vector<string> binaryTreePaths(TreeNode *root) {
  dfs(root);
  for (auto &str : res) // 删除最后的->
  {
    str.pop_back();
    str.pop_back();
  }
  return res;
}

vector<string> binaryTreePaths_1(TreeNode *root) // bfs
{
  vector<string> paths;
  if (root == nullptr)
    return paths;
  queue<TreeNode *> node_stack;
  queue<string> path_stack;
  node_stack.push(root);
  path_stack.push(to_string(root->val));
  while (!node_stack.empty()) {
    auto node = node_stack.front();
    auto path = path_stack.front();
    node_stack.pop();
    path_stack.pop();
    if (node->left == nullptr && node->right == nullptr)
      paths.push_back(path);
    if (node->left != nullptr) {
      node_stack.push(node->left);
      path_stack.push(path + "->" + to_string(node->left->val));
    }
    if (node->right != nullptr) {
      node_stack.push(node->right);
      path_stack.push(path + "->" + to_string(node->right->val));
    }
  }
  return paths;
}

int main() {
  TreeNode n9(9);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n5(5);
  TreeNode n0(0);

  TreeNode p(1);
  p.left = &n2;
  p.right = &n3;
  n2.right = &n5;

  auto res = binaryTreePaths_1(&p);
  for (auto c : res)
    cout << c << ' ';
}