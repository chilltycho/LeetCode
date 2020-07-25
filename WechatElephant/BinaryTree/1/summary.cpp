/*
二叉树是每个节点最多只有两个分支的树。
递归定义：1.空树是一个二叉树 2.若T1,T2是二叉树，则用一个根节点连接T1，T2得到也是二叉树
根据先递归左、根、右节点分为前序、中序、后序遍历。

递归本质：将问题分解为子问题
*/
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    //cout << root->val<<' ';//先序
    print(root->left);
    cout<<root->val<<' ';//中序
    print(root->right);
                        //后序
}
int main()
{
    TreeNode root(5);
    TreeNode n8(8);
    TreeNode n11(11);
    TreeNode n13(13);
    TreeNode n4(4);
    TreeNode n44(4);
    TreeNode n7(7);
    TreeNode n2(2);
    TreeNode n1(1);

    root.left = &n4;
    root.right = &n8;
    n4.left = &n11;
    n8.left = &n13;
    n8.right = &n44;
    n44.right = &n1;
    n11.left = &n7;
    n11.right = &n2;
    print(&root);
}