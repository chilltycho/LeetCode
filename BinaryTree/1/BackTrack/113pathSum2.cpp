/*给定一个二叉树和目标和，找出所有从根节点到叶子节点路径总和等于给定目标和的路径*/
#include <stack>
#include "../TreeNode.h"
using namespace std;

vector<int> path;
vector<vector<int>> res;

void traverse(TreeNode *root, int sum)
{
    if (root == nullptr)
        return;
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) //叶节点
        if (root->val == sum)
        {
            res.push_back(path);
            //return; // 不接return，path应将最后一个元素弹出
        }

    traverse(root->left, sum - (root->val));
    traverse(root->right, sum - (root->val));
    path.pop_back(); //回溯
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    traverse(root, sum);
    return res;
}

vector<vector<int>> mres;
vector<int> mtemp;
void dfs(TreeNode *root, int sum)
{
    int resum = sum - root->val;
    mtemp.push_back(root->val);
    if (resum == 0 && root->left == nullptr && root->right == nullptr) //叶子节点
        mres.push_back(mtemp);
    if (root->left != nullptr)
        dfs(root->left, resum);
    if (root->right != nullptr)
        dfs(root->right, resum);
    mtemp.pop_back();
}

vector<vector<int>> pathSum_1(TreeNode *root, int sum)
{
    if (root != nullptr)
        dfs(root, sum);
    return mres;
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