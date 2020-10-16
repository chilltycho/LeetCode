//翻转二叉树
#include <iostream>
#include "../TreeNode.h"
using namespace std;

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main()
{
    vector<int> vi{4, 2, 7, 1, 3, 6, 9};
    auto t = vecToTree(vi);
    auto res = invertTree(t);
    preprint(res);
}