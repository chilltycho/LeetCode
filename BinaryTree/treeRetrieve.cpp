#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root) //前序
{
    if (root == nullptr)
        return;
    //cout << root->val << ' ';//前序：先当前节点，再左节点，再右节点
    dfs(root->left);
    //cout<<root->val<<' ';//中序：先左节点，再当前节点，再右节点
    dfs(root->right);
    cout << root->val << ' '; //先左、右节点，再当前节点
}

int main()
{
#if 0
    TreeNode r(5);
    TreeNode n2(2);
    TreeNode n6(6);
    TreeNode n1(1);
    TreeNode n4(4);
    TreeNode n7(7);
    TreeNode n3(3);

    r.left = &n2;
    r.right = &n6;
    n2.left = &n1;
    n2.right = &n4;
    n4.left = &n3;
    n6.right = &n7;
#endif
    TreeNode r(1);
    TreeNode n2(2);
    TreeNode n5(5);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n6(6);
    TreeNode n7(7);

    r.left = &n2;
    r.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    n5.left = &n7;
    dfs(&r);
}