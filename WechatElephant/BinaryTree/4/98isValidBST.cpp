#include <iostream>
using namespace std;
/*给定二叉树，判断是否为BST。节点左子树只包含小于当前节点，右子树大于当前节点*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool valid;
void dfs(TreeNode *root, TreeNode *prev)
{
    if (root == nullptr)
        return;
    dfs(root->left, prev);
    if (prev != nullptr && prev->val > root->val)
    {
        valid = false;
        return;
    }
    prev = root;
    dfs(root->right, prev);
}

bool isValidBST(TreeNode *root) //中序遍历递增，比较相邻节点
{
    valid = true;
    TreeNode *prev = nullptr;
    dfs(root, prev);
    return valid;
}

int main()
{
    TreeNode r(2);
    TreeNode n1(1);
    TreeNode n3(3);

    r.left = &n1;
    r.right = &n3;

    TreeNode r1(5);
    TreeNode n4(4);
    TreeNode n6(6);
#if 1
    r1.left = &n1;
    r1.right = &n4;
    n4.left = &n3;
    n4.right = &n6;
#endif
    cout << isValidBST(&r1);
}