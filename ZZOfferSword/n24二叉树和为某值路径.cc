#include "../BinaryTree/TreeNode.h"
#include <vector>
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
            return;
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