//判断B是否为A的子结构，即A中有和B中相同结构和节点值
#include "TreeNode.h"
#include <cassert>

/**两步工作：
 * 遍历A中每个节点nA，对应isSubStructure(A,B)
 * 判断树A中以nA为根节点的子树是否包含树B。对应recur(A,B)
 */
bool dfs(TreeNode *a, TreeNode *b) {
  // B匹配完成
  if (b == nullptr)
    return true;
  // 匹配失败
  if (a == nullptr || b->val != a->val)
    return false;
  return dfs(a->left, b->left) && dfs(a->right, b->right);
}

bool isSubStructure(TreeNode *A, TreeNode *B) {
  if (A == nullptr || B == nullptr)
    return false;
  // B是A左子树子结构||B是A右子树子结构||以节点A为根节点的子树包含树B
  return isSubStructure(A->left, B) || isSubStructure(A->right, B) || dfs(A, B);
}

int main() {
  vector<int> via{3, 4, 5, 1, 2};
  vector<int> vib{4, 1};
  auto ta = vecToTree(via);
  auto tb = vecToTree(vib);
  assert(isSubStructure(ta, tb));
}
