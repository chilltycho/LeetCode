//判断二叉树是否镜像对称
#include "../TreeNode.h"
#include <cassert>
#include <queue>
using namespace std;
bool isSymmetric(TreeNode *root) // bfs
{
  queue<TreeNode *> mq;
  mq.push(root);
  mq.push(root);
  while (!mq.empty()) {
    auto l = mq.front();
    mq.pop();
    auto r = mq.front();
    mq.pop();
    if (l == nullptr && r == nullptr)
      continue;
    if (l == nullptr || r == nullptr)
      return false;
    if (l->val != r->val)
      return false;
    mq.push(l->left);
    mq.push(r->right);
    mq.push(l->right);
    mq.push(r->left);
  }
  return true;
}
//法二
bool dfs(TreeNode *l, TreeNode *r) {
  if (l == nullptr && r == nullptr)
    return true;
  if (l == nullptr || r == nullptr)
    return false;
  if (l->val != r->val)
    return false;
  return dfs(l->left, r->right) && dfs(l->right, r->left);
}

bool isSymmeric_1(TreeNode *root) {
  if (root == nullptr)
    return true;
  return dfs(root->left, root->right);
}

int main() {
  vector<int> vi{1, 2, 2, 3, 4, 4, 3};
  auto t1 = vecToTree(vi);
  assert(isSymmetric(t1));
}