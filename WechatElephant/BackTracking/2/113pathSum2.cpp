/*给定一个二叉树和目标和，找出所有从根节点到叶子节点路径总和等于给定目标和的路径*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traverse(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &res)
{
    if (root == nullptr)
        return;
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) //叶节点
        if (root->val == sum)
            res.push_back(path);
    int target = sum - root->val;
    traverse(root->left, target, path, res);
    traverse(root->right, target, path, res);
    path.pop_back(); //回溯
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    vector<vector<int>> res;
    vector<int> path;
    traverse(root, sum, path, res);
    return res;
}

vector<vector<int>> mres;
vector<int> mtemp;
void dfs(TreeNode *root, int sum)
{
    int resum = sum - root->val;
    mtemp.push_back(root->val);
    if (resum == 0 && root->left == nullptr && root->right == nullptr)//叶子节点
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
    TreeNode root(5);
    TreeNode n4(4);
    TreeNode n8(8);
    TreeNode n11(11);
    TreeNode n13(13);
    TreeNode n41(4);
    TreeNode n7(7);
    TreeNode n2(2);
    TreeNode n5(5);
    TreeNode n1(1);

    root.left = &n4;
    root.right = &n8;
    n4.left = &n11;
    n8.left = &n13;
    n8.right = &n41;
    n11.left = &n7;
    n11.right = &n2;
    n41.left = &n5;
    n41.right = &n1;

    auto res = pathSum(&root, 22);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}