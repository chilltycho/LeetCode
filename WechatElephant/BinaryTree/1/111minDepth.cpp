//给定二叉树，找出其最小深度，最小深度是从根节点到最近叶子节点的最短路径上的节点数量
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

int minDepth(TreeNode *root)//层序
{
    if (root == nullptr)
        return 0;
    queue<TreeNode *> mq;
    int res = 1;
    mq.push(root);
    while (!mq.empty())
    {
        int size = mq.size();
        for (int i = 0; i < size; i++)
        {
            auto node = mq.front();
            mq.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                return res;
            }
            if (node->left != nullptr)
                mq.push(node->left);
            if (node->right != nullptr)
                mq.push(node->right);
        }
        res++;//注意深度增加位置。
    }
    return -1;
}

int minDepth_1(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr) //处理[1,2]的情况，此时最小深度为2。区分叶节点
        return 1 + minDepth_1(root->right);
    if (root->right == nullptr)
        return 1 + minDepth_1(root->left);
    return min(1 + minDepth_1(root->left), 1 + minDepth_1(root->right));
}

int main()
{
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);

    TreeNode p(3);
    p.left = &n9;
    p.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    cout << minDepth_1(&p);
}