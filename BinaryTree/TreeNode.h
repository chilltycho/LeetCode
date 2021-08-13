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

void freeTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

#if 0

struct TreeNode
{
    int val = 0;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

shared_ptr<TreeNode> createTree(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    auto root = make_shared<TreeNode>(nums[0]);
    queue<shared_ptr<TreeNode>> mq;
    mq.push(root);
    int i = 1, len = nums.size();
    while (mq.size())
    {
        auto node = mq.front();
        mq.pop();
        if (i < len && nums[i] != -1)
        {
            node->left = make_shared<TreeNode>(nums[i]);
            mq.push(node->left);
        }
        ++i;
        if (i < len && nums[i] != -1)
        {
            node->right = make_shared<TreeNode>(nums[i]);
            mq.push(node->right);
        }
        ++i;
    }
    return root;
}

void preprint(shared_ptr<TreeNode> root)
{
    if (!root)
        return;
    cout << root->val << ' ';
    preprint(root->left);
    preprint(root->right);
}
#endif