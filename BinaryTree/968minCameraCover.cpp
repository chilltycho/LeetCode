/*给定一个二叉树，我们在树的节点上安装摄像头。
节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
计算监控树的所有节点所需的最小摄像头数量。*/
#include "TreeNode.h"
using namespace std;
// 自底向上推导，尽量让叶子节点的父节点安装摄像头
/*
三种状态：该节点无覆盖，本节点有摄像头，本节点有覆盖,0,1,2
空节点是什么状态？有覆盖
*/
int res = 0;
int dfs(TreeNode *cur) {
  if (cur == nullptr) // 空节点，有覆盖
    return 2;
  int l = dfs(cur->left);
  int r = dfs(cur->right);
  if (l == 2 && r == 2) // 左右节点均有覆盖，则该节点无覆盖
    return 0;
  if (l == 0 || r == 0) {
    // 有一个孩子没覆盖，该节点应放摄像头
    ++res;
    return 1;
  } else if (l == 1 || r == 1)
    return 2;
  else
    return -1; // 永远不执行
}

int minCameraCover(TreeNode *root) {
  if (dfs(root) == 0) // root无覆盖，
    ++res;
  return res;
}

int main() {
  vector<int> vi{0, 0, 0, -1, 0};
  auto root = vecToTree(vi);
  cout << minCameraCover(root) << endl;
}

