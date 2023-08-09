//给定二叉树，找出其最大深度，最大深度是从根节点到最近叶子节点的最长路径上的节点数量
#include <queue>
#include "../TreeNode.h"
#include <cassert>
using namespace std;

int maxDepth(TreeNode *root) 
{
    //解决的是根节点到最远叶子节点的最长路径
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    vector<int> vi{3, 9, 20, -1, -1, 15, 7};
    auto t1 = vecToTree(vi);
    assert(3 == maxDepth(t1));
}