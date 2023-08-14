#include "../TreeNode.h"
#include <deque>
using namespace std;
//找到每行中最大的数
vector<int> largestValues(TreeNode *root) {
  vector<int> res;
  if (root == nullptr)
    return res;
  deque<TreeNode *> mq;
  mq.push_back(root);
  while (!mq.empty()) {
    int maxval = INT16_MIN;
    int n = mq.size();
    for (int i = 0; i < n; i++) {
      auto node = mq.front();
      maxval = max(node->val, maxval);
      mq.pop_front();
      if (node->left != nullptr)
        mq.push_back(node->left);
      if (node->right != nullptr)
        mq.push_back(node->right);
    }
    res.push_back(maxval);
  }
  return res;
}

vector<int> res;
void dfs(TreeNode *root, int depth) {
  if (root == nullptr)
    return;
  if (depth == res.size()) //总是将到达新层第一个元素保存
    res.push_back(root->val);
  else {
    res[depth] = max(root->val, res[depth]); //同层元素更新
  }
  dfs(root->left, depth + 1);
  dfs(root->right, depth + 1);
}

vector<int> largestValues_1(TreeNode *root) {
  dfs(root, 0);
  return res;
}

int main() {
  vector<int> vi{1, 3, 2, 5, 3, -1, 9};
  auto root = vecToTree(vi);
  auto vii = largestValues_1(root);
  for (auto c : vii) {
    cout << c << ' ';
  }
}
