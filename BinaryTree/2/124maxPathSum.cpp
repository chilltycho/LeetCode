#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int res;
//返回经过root的单边分支最大和，max(root,root+left,root+right)
int dfs(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftsum = max(0, dfs(root->left)); //不能在外面定义。
    int rightsum = max(0, dfs(root->right));//计算右边分支最大值，右边分支如果为负数还不如不选
    res = max(res, root->val + leftsum + rightsum);//left->root->right作为路径与历史最大值作比较
    return root->val + max(leftsum, rightsum);//返回经过root的单边最大分支给上游
}

int maxPathSum(TreeNode *root)
{
    res = INT_MIN;
    dfs(root);
    return res;
}

int main()
{
    TreeNode root(-10);
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);

    root.left = &n9;
    root.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    cout << maxPathSum(&root);
}