#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using std::cout;
using std::queue;
using std::stack;
using std::vector;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

void preprint(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << ' ';
        preprint(root->left);
        preprint(root->right);
    }
}

void inprint(TreeNode *root)
{
    if (root == nullptr)
        return;
    inprint(root->left);
    cout << root->val << ' ';
    inprint(root->right);
}

void posprint(TreeNode *root)
{
    if (root == nullptr)
        return;
    posprint(root->left);
    posprint(root->right);
    cout << root->val << ' ';
}

TreeNode *vecToTree(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    queue<TreeNode *> nodeQueue;
    TreeNode *root = new TreeNode(nums[0]);
    nodeQueue.push(root);
    int len = nums.size();
    int i = 1;
    while (!nodeQueue.empty())
    {
        auto node = nodeQueue.front();
        nodeQueue.pop();
        if (i < len && nums[i] != -1)
        {
            node->left = new TreeNode(nums[i]);
            nodeQueue.push(node->left);
        }
        i++;
        if (i < len && nums[i] != -1)
        {
            node->right = new TreeNode(nums[i]);
            nodeQueue.push(node->right);
        }
        i++;
    }
    return root;
}
