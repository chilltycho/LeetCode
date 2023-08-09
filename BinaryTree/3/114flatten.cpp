#include "../TreeNode.h"
using namespace std;

TreeNode *pre = nullptr;
//若使用前序，则右枝会被覆盖。故使用后序。右->左->根
void flatten(TreeNode *root) {
  //将二叉树变为链表
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

int main() {
  vector<int> vi{1, 2, 5, 3, 4, -1, 6};
  auto t1 = vecToTree(vi);
  flatten(t1);
  printlist(t1);
}
