#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if(p==nullptr||q==nullptr)//考虑[1,2] [1,null,2]
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode n2(2);
    TreeNode n22(2);
    TreeNode n3(3);
    TreeNode n33(3);

    TreeNode p(1);
    TreeNode q(1);
    p.left=&n2;
    p.right=&n3;
    q.left=&n22;
    q.right=&n33;
    
    cout<<isSameTree(&p,&q);
}