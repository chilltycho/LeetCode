/*给定二叉搜索树根节点root,两节点被错误交换。在不改变结构情况下，恢复树*/
#include "TreeNode.h"
#include <algorithm>
#include <stack>
using namespace std;
vector<TreeNode *> vi;
//搜索二叉树中序遍历后应为升序
void dfs(TreeNode *root)
{
    if (root == nullptr)
        return;
    dfs(root->left);
    vi.push_back(root);
    dfs(root->right);
}

void recoverTree(TreeNode *root)
{
    dfs(root);
    TreeNode *x = nullptr;
    TreeNode *y = nullptr;

    for (int i = 0; i < vi.size() - 1; i++)
    {
        if (vi[i]->val > vi[i + 1]->val)
        {
            y = vi[i + 1];
            if (x == nullptr)
                x = vi[i];
        }
    }
    if (x != nullptr && y != nullptr)
    {
        int tmp = x->val;
        x->val = y->val;
        y->val = x->val;
    }
}

void recoverTree_1(TreeNode *root)
{
    stack<TreeNode *> stk;
    TreeNode *x = nullptr;
    TreeNode *y = nullptr;
    TreeNode *pred = nullptr;
    while (!stk.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (pred != nullptr && root->val < pred->val)
        {
            y = root;
            if (x == nullptr)
                x = pred;
            else
                break;
        }
        pred = root;
        root = root->right;
    }
    swap(x->val, y->val);
}



