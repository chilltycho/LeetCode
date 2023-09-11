#include "TreeNode.h"
// 二叉树的前序，中序和后序遍历是根据根结点的位置来判断
// 前序：根左右
// 中序：左根右
// 后序：左右根
// 叶子结点也需要判断左右节点，只不过左右节点都是空

// 非递归前序遍历，根左右
//(1) 从根结点开始，向左遍历压栈并输出
//(2) 一直找到二叉树最左边的结点，将最左侧的叶子结点压入栈
//(3) 出栈，指向该结点的右孩子
//(4) 将右孩子作为根节点重复(1)(2)(3)
void Pretravel(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<TreeNode *> st;
  TreeNode *p = root;

  while (p || !st.empty()) {
    while (p) {
      cout << p->val;
      st.push(p);
      p = p->left;
    }

    if (!st.empty()) {
      p = st.top();
      st.pop();
      p = p->right;
    }
  }
}

// 非递归中序遍历，左根右
// 先输出最左侧叶子结点
//(1) 从根结点开始，往左遍历压栈
//(2) 找到最左侧的叶子结点,也将其压栈
//(3) 出栈，输出结点值，并指向该结点的右孩子
//(4) 将右孩子作为根结点继续(1)(2)(3)
void Intravel(TreeNode *root) {
  if (root == NULL)
    return;
  stack<TreeNode *> st;
  TreeNode *p = root;

  while (!st.empty() || p) {
    while (p) {
      st.push(p);
      p = p->left;
    }

    if (!st.empty()) {
      p = st.top();
      st.pop();
      cout << p->val;
      p = p->right;
    }
  }
}

// 非递归后序遍历，左右根
//  维护一个pre结点
//(1) 从根结点开始，往左遍历压栈
//(2) 找到最左侧的叶子结点,也将其压栈
//(3) 出栈，判断当前的结点是不是叶子结点或是不是根结点(上一次访问的是右孩子)
//(4) 若是，输出结点值，更新pre指针
//(5) 若不是，指向右孩子，重复(1)(2)(3)(4)
void behtravel(TreeNode *root) {
  if (NULL == root)
    return;
  stack<TreeNode *> st;
  TreeNode *p = root;
  TreeNode *pre = NULL;
  while (!st.empty() || p) {
    while (p) {
      st.push(p);
      p = p->left;
    }
    if (!st.empty()) {
      p = st.top();
      st.pop();

      // 右孩子为空(左叶子结点和右叶子结点) 或
      // 刚刚访问的是该结点的右孩子(根结点)
      if (!p->right || pre == p->right) {
        cout << p->val;
        pre = p;
      }
      // 右孩子不为空，则将刚刚出栈的结点重新压入，指向结点的右孩子
      else {
        st.push(p);
        p = p->right;
      }
    }
  }
}
