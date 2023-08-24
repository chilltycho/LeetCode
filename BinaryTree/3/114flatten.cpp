#include "../TreeNode.h"
#include <vcruntime.h>
using namespace std;

TreeNode *pre = nullptr;
// 若使用前序，则右枝会被覆盖。故使用后序。右->左->根
void flatten(TreeNode *root) {
  // 将二叉树变为链表
  if (root == nullptr)
    return;
  flatten(root->right);
  flatten(root->left);
  root->right = pre;
  root->left = nullptr;
  pre = root;
}

void printlist(TreeNode *root) {
  if (root == nullptr)
    return;
  cout << root->val << ' ';
  printlist(root->right);
}

void dfs(TreeNode *node, queue<TreeNode *> &mq) {
  if (!node) {
    return;
  }
  mq.push(node);
  dfs(node->left, mq);
  dfs(node->right, mq);
}

void flatten1(TreeNode *root) {
  if (!root) {
    return;
  }

  queue<TreeNode *> mq;
  dfs(root, mq);
  root = mq.front();
  int len = mq.size();
  auto top = mq.front();
  while (len) {
    top = mq.front();
    mq.pop();
    top->left = NULL;
    top->right = mq.front();
    --len;
  }
  top->right=NULL;
}

int main() {
  vector<int> vi{1, 2, 5, 3, 4, -1, 6};
  auto t1 = vecToTree(vi);
  flatten1(t1);
  printlist(t1);
}
