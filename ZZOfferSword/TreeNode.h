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

vector<int> inorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    auto rt = root;
    while (rt || st.size())
    {
        if (rt)
        {
            st.push(rt);
            rt = rt->left;
        }
        else
        {
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            rt = node->right;
        }
    }
    return res;
}

vector<int> preorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    auto rt = root;
    while (rt || st.size())
    {
        while (rt)
        {
            res.push_back(rt->val); // 一直向左走，把当前值记录，把右节点入栈
            st.push(rt->right);
            rt = rt->left;
        }
        rt = st.top();
        st.pop();
    }
    return res;
}

vector<int> postorder(TreeNode *root)
{
    stack<TreeNode *> stk;
    auto rt = root;
    vector<int> res;
    while (rt || stk.size())
    {
        while (rt)
        {
            res.push_back(rt->val);
            stk.push(rt->left);
            rt = rt->right;
        }
        rt = stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}