/*节点的坡度定义为该节点左子树的节点之和和右子树节点之和的差的绝对值。空节点的坡度是0。*/
#include "../TreeNode.h"
using namespace std;

int titlt;

int dfs(TreeNode *root) {
  if (root == nullptr)
    return 0;
  int leftt = dfs(root->left);
  int rightt = dfs(root->right);
  titlt += abs(leftt - rightt);
  return root->val + leftt + rightt;
}

int findTilt(TreeNode *root) {
  titlt = 0;
  dfs(root);
  return titlt;
}

int main() {
  vector<int> vi{1, 2, 3};
  auto t1 = vecToTree(vi);
  cout << findTilt(t1) << endl;
}
