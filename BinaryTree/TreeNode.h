#include <vector>
#include <iostream>
using std::cout;
using std::vector;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
class BST
{
public:
    TreeNode *root = nullptr;

public:
    BST(int k)
    {
        root = new TreeNode(k);
    }
    TreeNode *insert_i(TreeNode *node, int key)
    {
        if (node == nullptr)
            return new TreeNode(key);
        if (node->left != nullptr)
        {
            node->right = insert_i(node->right, key);
            return node;
        }
        else
        {
            node->left = insert_i(node->left, key);
            return node;
        }
    }
    BST(vector<int> &nums)
    {
        for (auto c : nums)
            root = insert_i(root, c);
    }
};

void print(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << ' ';
        print(root->left);
        print(root->right);
    }
}