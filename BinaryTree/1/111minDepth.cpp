//给定二叉树，找出其最小深度，最小深度是从根节点到最近叶子节点的最短路径上的节点数量
#include <cassert>
#include "../TreeNode.h"
#include <queue>
using namespace std;

int minDepth(TreeNode *root) //层序
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
        res++; //注意深度增加位置。
    }
    return -1;
}

int minDepth_1(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr) // 叶子节点
        return 1;
    if (root->left == nullptr)
        return 1 + minDepth_1(root->right);
    if (root->right == nullptr)
        return 1 + minDepth_1(root->left);
    return 1 + min(minDepth_1(root->left), minDepth_1(root->right));
}

int main()
{
    vector<int> vi{3, 9, 20, -1, -1, 15, 7};
    auto t1 = vecToTree(vi);
    assert(2 == minDepth(t1));
}