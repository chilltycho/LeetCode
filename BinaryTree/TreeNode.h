#include <vector>
#include <iostream>
#include <queue>
#include <stack>
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
//迭代法前序，根左右
void preorder_ite(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->right != nullptr)
            st.push(node->right);
        if (node->left != nullptr)
            st.push(node->left);
    }
}
//迭代法中序 左根右
void inOrder_ite(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *cur = root;
    stack<TreeNode *> stk;
    while (!stk.empty() || cur != nullptr)
    {
        while (cur != nullptr) //向左遍历，将最左侧元素压入栈
        {
            stk.push(cur);
            cur = cur->left;
        }
        auto node = stk.top();
        stk.pop();
        cout << node->val << ' ';
        if (node->right != nullptr)
            cur = node->right;
    }
}
//后序遍历，左右根 前序遍历为根左右，转化成根右左，再利用栈倒序打印
void postOrder_ite(TreeNode *root)
{
    if (root = nullptr)
        return;
    stack<TreeNode *> stk1;
    stack<TreeNode *> stk2;
    stk1.push(root);
    while (!stk1.empty())
    {
        auto node = stk1.top();
        stk1.pop();
        stk2.push(node);
        if (node->left != nullptr)
            stk1.push(node->left);
        if (node->right != nullptr)
            stk1.push(node->right);
    }
    while (!stk2.empty())
    {
        auto node = stk2.top();
        stk2.pop();
        cout << node->val << ' ';
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