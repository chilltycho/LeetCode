//按之字形顺序打印二叉树，第一行从左到右，第二层从右到左...
#include "../TreeNode.h"
using namespace std;

vector<deque<int>> ret;

void dfs(int depth, TreeNode *root) {
  if (root == nullptr)
    return;
  if (ret.size() == depth)
    ret.emplace_back(deque<int>());
  if (depth & 1) //从右向左
    ret[depth].emplace_front(root->val);
  else //从左向右
    ret[depth].emplace_back(root->val);
  dfs(depth + 1, root->left);
  dfs(depth + 1, root->right);
}

vector<deque<int>> levelOrder_dfs(TreeNode *root) {
  dfs(0, root);
  return ret;
}

vector<vector<int>> bfs(TreeNode *root) {
  deque<TreeNode *> mq;
  vector<vector<int>> res;
  if (root == nullptr)
    return res;
  bool isleft = true;
  mq.push_back(root);
  while (!mq.empty()) {
    int size = mq.size();
    vector<int> temp;
    if (isleft) {
      for (int i = 0; i < size; i++) {
        auto node = mq.front();
        mq.pop_front();
        temp.push_back(node->val);
        if (node->left)
          mq.push_back(node->left);
        if (node->right)
          mq.push_back(node->right);
      }
    } else {
      for (int i = 0; i < size; i++) {
        auto node = mq.back();
        mq.pop_back();
        temp.push_back(node->val);
        if (node->right)
          mq.push_front(node->right);
        if (node->left)
          mq.push_front(node->left);
      }
    }
    res.push_back(temp);
    isleft = !isleft;
  }
  return res;
}

int main() {
  vector<int> vi{3, 9, 20, -1, -1, 15, 7};
  auto root = vecToTree(vi);
  levelOrder_dfs(root);
  for (const auto &c : ret) {
    for (const auto &t : c)
      cout << t << ' ';
    cout << endl;
  }
}
