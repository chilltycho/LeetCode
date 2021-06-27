/*给定二叉树，计算直径长度，是两个节点路径长度中的最大值，可能也可能不穿过根节点*/
#include "../TreeNode.h"
using namespace std;

/*二叉树最长路径=max(左子树最长路径，右子树最长路径，左子树深度+右子树深度）*/
int diameter = 0;
// 注意是边的数量
int dfs(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = dfs(root->left);//左节点为根的最大路径长度
    int right = dfs(root->right);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);//当前节点为根的最大路径长度
}
int diameterOfBinaryTree(TreeNode *root)
{
    dfs(root);
    return diameter;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto t1 = vecToTree(vi);
    cout << diameterOfBinaryTree(t1) << endl;
}