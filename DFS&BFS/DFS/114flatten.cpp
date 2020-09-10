#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void flatten(TreeNode *node)
{
    while (node != nullptr)
    {
        if (node->left == nullptr)
            node = node->right;
        else
        {
            TreeNode *pre = node->left;
            while (pre->right != nullptr)
                pre = pre->right;
            pre->right = node->right;
            node->right = node->left;
            node->left = nullptr;
            node = node->right;
        }
    }
}
TreeNode *pre = nullptr;
void flatten_1(TreeNode *root)
{
    if (root == nullptr)
        return;
    flatten_1(root->right);
    flatten_1(root->left);
    root->right = pre;
    root->left = nullptr;
    pre = root;
}
void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << ' ';
    print(root->right);
}
int main()
{
    TreeNode r1(1);
    TreeNode r2(2);
    TreeNode r3(3);
    TreeNode r4(4);
    TreeNode r5(5);
    TreeNode r6(6);
    r1.left = &r2;
    r1.right = &r5;
    r2.left = &r3;
    r2.right = &r4;
    r5.right = &r6;

    flatten_1(&r1);
    print(&r1);
}