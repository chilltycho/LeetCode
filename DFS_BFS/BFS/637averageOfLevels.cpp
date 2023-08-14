#include "../TreeNode.h"
#include <queue>
using namespace std;

vector<double> averageOfLevels(TreeNode *root) {
  vector<double> res;
  if (root == nullptr)
    return res;
  queue<TreeNode *> mq;
  mq.push(root);
  while (!mq.empty()) {
    int n = mq.size();
    double average = 0.0;
    for (int i = 0; i < n; i++) {
      auto node = mq.front();
      average += node->val;
      mq.pop();
      if (node->left != nullptr)
        mq.push(node->left);
      if (node->right != nullptr)
        mq.push(node->right);
    }
    average /= n;
    res.push_back(average);
  }
  return res;
}

void dfs(TreeNode *root, int depth, vector<int> &counts, vector<double> &sums) {
  if (root == nullptr)
    return;
  if (depth >= sums.size()) {
    sums.push_back(1.0 * root->val);
    counts.push_back(1);
  } else {
    sums[depth] += root->val;
    counts[depth]++;
  }
  dfs(root->left, depth + 1, counts, sums);
  dfs(root->right, depth + 1, counts, sums);
}
vector<double> averageOfLevels_dfs(TreeNode *root) {
  vector<int> counts;  //每层节点个数
  vector<double> sums; //每层节点总和
  dfs(root, 0, counts, sums);
  for (size_t i = 0; i < counts.size(); i++)
    sums[i] /= counts[i];
  return sums;
}
int main() {
  vector<int> vi{3, 9, 20, -1, -1, 15, 7};
  auto t1 = vecToTree(vi);
  auto res = averageOfLevels_dfs(t1);
  for (auto c : res)
    cout << c << ' ';
}