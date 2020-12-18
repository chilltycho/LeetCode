//从上到下打印二叉树每个节点，同层节点从左到右打印
#include "TreeNode.h"
using namespace std;

vector<int> levelOrder_bfs(TreeNode *root)
{
    vector<int> res;
    queue<TreeNode *> mq;
    if (root == NULL)
        return res;
    mq.push(root);
    while (!mq.empty())
    {
        auto node = mq.front();
        res.push_back(node->val);
        mq.pop();
        if (node->left != NULL)
            mq.push(node->left);
        if (node->right != NULL)
            mq.push(node->right);
    }
    return res;
}

vector<int> levelOrder_dfs(TreeNode *root)
{

}
