#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr && t2 == nullptr)
        return true;
    if (t1 == nullptr || t2 == nullptr)
        return false;
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t2->left, t1->right);
}

bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

bool isSymmetric_1(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(root);
    while (!q.empty())
    {
        auto t1 = q.front();
        q.pop();
        auto t2 = q.front();
        q.pop();
        if (t1 == nullptr && t2 == nullptr)
            continue; //注意不能直接返回true
        if (t1 == nullptr || t2 == nullptr)
            return false;
        if (t1->val != t2->val)
            return false;
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}