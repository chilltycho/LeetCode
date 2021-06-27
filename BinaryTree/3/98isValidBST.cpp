#include "../TreeNode.h"
#include <cassert>
using namespace std;
/*给定二叉树，判断是否为BST。节点左子树只包含小于当前节点，右子树大于当前节点*/
int pre = INT32_MIN;
bool isValidBST(TreeNode *root) //中序遍历递增，比较相邻节点
{
    if (root == nullptr)
        return true;
    if (!isValidBST(root->left))
        return false;
    if (root->val <= pre)
        return false;
    pre = root->val;
    return isValidBST(root->right);
}

bool valid = true;
void dfs(TreeNode *root)
{
    if (root == nullptr)
        return;
    dfs(root->left);
    if (root->val <= pre)
    {
        valid = false;
    }
    pre = root->val;
    dfs(root->right);
}

bool isValidBST_1(TreeNode *root)
{
    dfs(root);
    return valid;
}

int main()
{
    vector<int> vi{1, 1};
    // assert(!isValidBST_1(vecToTree(vi)));

    vector<int> vi2{5, 1, 4, -1, -1, 3, 6};
    assert(!isValidBST_1(vecToTree(vi2)));
}