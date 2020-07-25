/*给定二叉树和目标和，判断树中是否存在根节点到叶节点路径，节点和为目标和*/
#include <iostream>
#include<queue>
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
    cout << root->val << ' '; //中序
    print(root->right);
    //后序
}

bool hasPathSum(TreeNode *root, int sum) //注意sum为0，空树的情况，此时应输出false
{
    if (root == nullptr)
        return false;
    if (root->left == nullptr && root->right == nullptr)
        return sum == root->val;
    int target = sum - root->val;
    return hasPathSum(root->left, target) || hasPathSum(root->right, target);
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
    cout << hasPathSum(&root, 22);
}