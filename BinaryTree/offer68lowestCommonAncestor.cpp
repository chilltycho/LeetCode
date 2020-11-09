//求二叉搜索树p,q的最近公共祖先节点
#include"TreeNode.h"
#include<utility>
using namespace std;
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(p->val>q->val)
        swap(p,q);
    while(root)
    {
        if(root->val<p->val)//都在右子树
            root=root->right;
        else if(root->val>q->val)//都在左子树
            root=root->left;
        else
            break;
    }
    return root;
}

TreeNode* lowestCommonAncestor_re(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root->val<p->val&&root->val<q->val)
        return lowestCommonAncestor_re(root->right,p,q);
    if(root->val>p->val&&root->val>q->val)
        return lowestCommonAncestor_re(root->left,p,q);
    return root;
}