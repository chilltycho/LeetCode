#include <vector>
#include "TreeNode.h"
using namespace std;
vector<vector<int>> res;
void dfs(TreeNode *root, int depth)
{
    if (!root)
        return;
    if (depth >= res.size())
        res.push_back(vector<int>{});
    res[depth].push_back(root->val);
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
vector<int> PrintFromTopToBottom(TreeNode *root)
{
    dfs(root, 0);
    vector<int> ans;
    for (auto c : res)
    {
        for (auto cc : c)
            ans.push_back(cc);
    }
    return ans;
}