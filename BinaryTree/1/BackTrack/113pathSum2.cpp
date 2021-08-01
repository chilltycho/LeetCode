/*给定一个二叉树和目标和，找出所有从根节点到叶子节点路径总和等于给定目标和的路径*/
#include <stack>
#include "../../TreeNode.h"
#include <queue>
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

int main()
{
    vector<int> vi{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    auto t1 = vecToTree(vi);
    auto res = pathSum(t1, 22);
    for (const auto c : res)
    {
        for (const auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}