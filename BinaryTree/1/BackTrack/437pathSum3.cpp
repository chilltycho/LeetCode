/*给定二叉树，找出路径和等于给定数值的路径总数，路径无需从根节点开始，无需
在叶节点结束*/
#include <queue>
#include "../../TreeNode.h"
#include <cassert>
using namespace std;
int res = 0;
void dfs(TreeNode *root, int sum)
{
    if (root == nullptr)
        return;
    sum -= root->val;
    if (sum == 0)
        ++res;
    dfs(root->left, sum);
    dfs(root->right, sum);
}

int pathSum(TreeNode *root, int targetsum)
{
    if (root == nullptr)
        return 0;
    dfs(root, targetsum);
    pathSum(root->left, targetsum);
    pathSum(root->right, targetsum);
    return res;
}