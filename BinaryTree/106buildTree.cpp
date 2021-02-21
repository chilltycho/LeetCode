/*根据一棵树中序和后序遍历构造二叉树*/
/**
 * 后序遍历：[[左子树的后序遍历结果],[右子树的后序遍历结果],根]
 * 中序遍历:[[左子树的中序遍历结果],根,[右子树的中序遍历结果]]*/
#include "TreeNode.h"
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int, int> index;
TreeNode *helper(vector<int> &postorder, vector<int> &inorder,
                 int postorder_left, int postorder_right, int inorder_left, int inorder_right)
{
    if (postorder_left > postorder_right)
        return nullptr;
    int postorder_root = postorder_left;
    int inorder_root = index[postorder[postorder_root]];
    TreeNode *root = new TreeNode(postorder[postorder_root]);
    int size_left_subtree = inorder_root - inorder_left;
    root->left = helper(postorder, inorder, postorder_right - size_left_subtree + 1, postorder_right, inorder_left, inorder_root - 1);
    root->right = helper(postorder, inorder, postorder_left + 1, postorder_right - size_left_subtree, inorder_root + 1, inorder_right);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    reverse(postorder.begin(), postorder.end()); //变为根右左
    for (int i = 0; i < n; i++)
        index[inorder[i]] = i;
    return helper(postorder, inorder, 0, n - 1, 0, n - 1);
}

int main()
{
    vector<int> ino{9, 3, 15, 20, 7};
    vector<int> pos{9, 15, 7, 20, 3};
    auto tree = buildTree(ino, pos);
    preprint(tree);
}