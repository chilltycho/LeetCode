#include <vector>
#include <iostream>
#include <queue>
#include <memory>
using namespace std;

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

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto root = createTree(vi);
    preprint(root);
}