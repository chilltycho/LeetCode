//判断二叉树是否镜像对称
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

bool isSymmetric(TreeNode *root) //层序
{
    queue<TreeNode *> mq;
    mq.push(root);
    mq.push(root);
    while (!mq.empty())
    {
        auto l = mq.front();
        mq.pop();
        auto r = mq.front();
        mq.pop();
        if (l == nullptr && r == nullptr)
            continue;
        if (l == nullptr || r == nullptr)
            return false;
        if (l->val != r->val)
            return false;
        mq.push(l->left);
        mq.push(r->right);
        mq.push(l->right);
        mq.push(r->left);
    }
    return true;
}
//法二
bool dfs(TreeNode *l, TreeNode *r)
{
    if (l == nullptr && r == nullptr)
        return true;
    if (l == nullptr || r == nullptr)
        return false;
    if (l->val != r->val)
        return false;
    return dfs(l->left, r->right) && dfs(l->right, r->left);
}

bool isSymmeric_1(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return dfs(root->left, root->right);
}

int main()
{
    TreeNode r(1);
    TreeNode n21(2);
    TreeNode n22(2);
    TreeNode n31(3);
    TreeNode n32(3);
    TreeNode n41(4);
    TreeNode n42(4);
#if 0
    r.left=&n21;
    r.right=&n22;
    n21.left=&n31;
    n21.right=&n41;
    n22.left=&n42;
    n22.right=&n32;
#endif
    r.left = &n21;
    r.right = &n22;
    n21.right = &n31;
    n22.right = &n32;
    cout << isSymmeric_1(&r);
}