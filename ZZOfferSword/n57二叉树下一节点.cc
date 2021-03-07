/**
 * 给定二叉树，找出中序遍历下一节点。树节点不仅包含左右节点，同时包含指向父节点的指针
*/
#include <vector>
using namespace std;
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

TreeLinkNode *getnext(TreeLinkNode *pNode)
{
    if (!pNode)
        return nullptr;
    if (pNode->right)
    {
        pNode = pNode->right;
        while (pNode->left)
        {
            pNode = pNode->left;
        }
        return pNode;
    }
    while (pNode->next)
    {
        TreeLinkNode *root = pNode->next;
        if (root->left == pNode)
            return root;
        pNode = pNode->next;
    }
    return nullptr;
}

void preorder(TreeLinkNode *root, vector<TreeLinkNode *> &v)
{
    if (!root)
        return;
    preorder(root->left, v);
    v.push_back(root);
    preorder(root->right, v);
}

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    TreeLinkNode *root = nullptr;
    TreeLinkNode *tmp = pNode;
    while (tmp)
    {
        root = tmp;
        tmp = tmp->next;
    }
    vector<TreeLinkNode *> vt;
    preorder(root, vt);
    for (size_t i = 0; i < vt.size(); i++)
    {
        if (vt[i] == pNode && i + 1 != vt.size())
            return vt[i + 1];
    }
    return nullptr;
}