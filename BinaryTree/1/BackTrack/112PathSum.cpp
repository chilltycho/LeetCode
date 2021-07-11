/*给定二叉树和目标和，判断树中是否存在根节点到叶节点路径，节点和为目标和*/
#include <queue>
#include "../../TreeNode.h"
#include <cassert>
using namespace std;

bool hasPathSum(TreeNode *root, int sum) //注意sum为0，空树的情况，此时应输出false
{
    if (root == nullptr)
        return false;
    if (root->left == nullptr && root->right == nullptr)
        return sum == root->val;
    int target = sum - root->val;
    return hasPathSum(root->left, target) || hasPathSum(root->right, target);
}

int main()
{
    vector<int> vi{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    auto t1 = vecToTree(vi);
    assert(hasPathSum(t1, 22));
}