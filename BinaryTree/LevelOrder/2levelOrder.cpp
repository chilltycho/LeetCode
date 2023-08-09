//从上到下按层打印二叉树，同一层节点按左到右顺序打印，每层打印到一行
#include "../TreeNode.h"
using namespace std;

void dfs(TreeNode *root, vector<vector<int>> &res, int level) {
  if (!root)
    return;
  if (level >= res.size())
    res.emplace_back(vector<int>());
  res[level].emplace_back(root->val);
  dfs(root->left, res, level + 1);
  dfs(root->right, res, level + 1);
}

vector<vector<int>> bfs(TreeNode *root) {
  vector<vector<int>> res;
  queue<TreeNode *> mq;
  if (root == NULL)
    return res;
  mq.push(root);
  while (!mq.empty()) {
    int len = mq.size();
    vector<int> temp;

    for (int i = 0; i < len; i++) {
      auto node = mq.front();
      mq.pop();
      temp.push_back(node->val);
      if (node->left)
        mq.push(node->left);
      if (node->right)
        mq.push(node->right);
    }
    res.push_back(temp);
  }
  return res;
}

int main() {
  vector<int> vi{1, 2, 3, 4, 5, 6, 7};
  auto root = vecToTree(vi);
  vector<vector<int>> res;
  dfs(root, res, 0);
  for (auto c : res) {
    for (auto cc : c)
      cout << cc << " ";
    cout << endl;
  }
}
