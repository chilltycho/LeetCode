#include "../TreeNode.h"
#include <deque>
using namespace std;
//层序，第一层左向右，第二层右向左...
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);
  bool isleft = true;
  while (!nodeQueue.empty()) {
    deque<int> levelList;
    int size = nodeQueue.size();
    for (int i = 0; i < size; i++) {
      auto node = nodeQueue.front();
      nodeQueue.pop();
      if (isleft)
        levelList.push_back(node->val);
      else
        levelList.push_front(node->val);
      if (node->left)
        nodeQueue.push(node->left);
      if (node->right)
        nodeQueue.push(node->right);
    }
    ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
    isleft = !isleft;
  }
  return ans;
}

void dfs(TreeNode *cur, vector<deque<int>> &res, int level) {
  if (cur == nullptr)
    return;
  if (res.size() <= level)
    res.push_back(deque<int>{});
  if (level % 2 == 0)
    res[level].push_back(cur->val);
  else
    res[level].push_front(cur->val);
  dfs(cur->left, res, level + 1);
  dfs(cur->right, res, level + 1);
}

vector<vector<int>> zigzagLevelOrder_dfs(TreeNode *root) {
  vector<vector<int>> res;
  vector<deque<int>> vd;
  dfs(root, vd, 0);
  for (auto &dq : vd)
    res.emplace_back(vector<int>{dq.begin(), dq.end()});
  return res;
}

int main() {
  vector<int> vi{3, 9, 20, -1, -1, 15, 7};
  auto root = vecToTree(vi);
  auto vii = zigzagLevelOrder_dfs(root);
  for (auto c : vii) {
    for (auto cc : c)
      cout << cc << ' ';
    cout << endl;
  }
}

