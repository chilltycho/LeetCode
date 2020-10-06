#include <vector>
#include <iostream>
#include <queue>
using std::cout;
using std::queue;
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