#include "TreeNode.h"
#include <vector>
#include <queue>
using namespace std;
vector<deque<int>> res;
void dfs(TreeNode *root, size_t depth)
{
    if (root == nullptr)
        return;
    if (res.size() <= depth)
        res.push_back(deque<int>{});
    if (depth & 1)
    {
        res[depth].push_front(root->val);
    }
    else
        res[depth].push_back(root->val);
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
vector<vector<int>> Print(TreeNode *pRoot)
{
    dfs(pRoot, 0);
    vector<vector<int>> ans;
    for (size_t i = 0; i < res.size(); i++)
    {
        ans.push_back(vector<int>{});
        for (size_t j = 0; j < res[i].size(); j++)
        {
            ans[i].push_back(res[i][j]);
        }
    }
    return ans;
}