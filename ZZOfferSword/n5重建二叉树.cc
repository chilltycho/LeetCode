// 从前序和中序遍历构造二叉树,无重复数字
#include "TreeNode.h"
#include <stack>
#include <unordered_map>
using namespace std;
/*前序遍历:[根,[左子树前序遍历结果],[右子树的前序遍历结果]]
**中序遍历:[[左子树的中序遍历结果],根,[右子树的中序遍历结果]]
**思路:在中序遍历中定位到根节点,则可知道左子树和右子树节点数目,同一颗树前序
遍历,中序遍历长度相同,可对应到前序遍历结果中,对所有左右括号定位.*/
unordered_map<int, int> index; // 键为节点值，值为其在中序遍历中位置

TreeNode *helper(const vector<int> &preorder, const vector<int> &inorder,
                 int preorder_left, int preorder_right, int inorder_left,
                 int inorder_right) {
  if (preorder_left > preorder_right)
    return nullptr;
  // 前序遍历中第一个节点就是根节点
  int preorder_root = preorder_left;
  // 在中序遍历中定位根节点
  int inorder_root = index[preorder[preorder_root]];
  // 建立根节点
  TreeNode *root = new TreeNode(preorder[preorder_root]);
  // 左子树中节点数目
  int size_left_subtree = inorder_root - inorder_left;
  // 递归构造左子树，连接到根节点
  // 先序遍历中[从左边界+1开始的size_left_subtree个元素]对应中序遍历[从左边界开始到根节点-1]的元素
  root->left =
      helper(preorder, inorder, preorder_left + 1,
             preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
  // 递归构造右子树，连接到根节点
  // 先序遍历中[从左边界+1+左子树节点数目 到
  // 右边界]元素对应中序遍历[从根节点+1到右边界]元素
  root->right = helper(preorder, inorder, preorder_left + size_left_subtree + 1,
                       preorder_right, inorder_root + 1, inorder_right);
  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  int n = preorder.size();
  for (int i = 0; i < n; i++)
    index[inorder[i]] =
        i; // 构造哈希映射,快速定位根节点，键为节点值，值为其在中序遍历中位置
  return helper(preorder, inorder, 0, n - 1, 0, n - 1);
}