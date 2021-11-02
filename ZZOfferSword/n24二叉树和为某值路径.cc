#include "../BinaryTree/TreeNode.h"
#include <vector>
using namespace std;

vector<int> path;
vector<vector<int>> res;

void dfs(TreeNode *root, int target)
{
    if (root == nullptr)
        return;
    path.push_back(root->val);
    target = target - root->val;
    if (!root->left && !root->right && target == 0)
        res.push_back(path);
    dfs(root->left, target);
    dfs(root->right, target);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    dfs(root, sum);
    return res;
}