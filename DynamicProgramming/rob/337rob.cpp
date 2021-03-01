#include <iostream>
#include <cassert>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//只能偷无连线连接的二叉树节点

/*当前节点是否偷决定孩子节点是否偷，设计成状态，放在第2维，消除后效性。
dp[node][j],j=0不偷
状态转移：当前节点不偷，左右节点偷或不偷都行，选最大
         当前节点偷，左右节点均不能偷
使用后序遍历：子节点陆续汇报信息给父节点，最后到根节点*/
pair<int, int> dfs(TreeNode *node)
{
    if (node == nullptr)
        return make_pair(0, 0);
    pair<int, int> left = dfs(node->left);
    pair<int, int> right = dfs(node->right);

    pair<int, int> dp;
    //node不偷，以node为根节点的子树能偷取的最大价值
    dp.first = max(left.first, left.second) + max(right.first, right.second); 
    //node偷，以node为根节点的子树能偷取的最大价值
    dp.second = node->val + left.first + right.first;                         
    return dp;
}

int rob(TreeNode *root)
{
    pair<int, int> res = dfs(root);
    return max(res.first, res.second);
}

int main()
{
    TreeNode r(3);
    TreeNode r2(2);
    TreeNode r3(3);
    TreeNode r31(3);
    TreeNode r1(1);
    r.left = &r2;
    r.right = &r31;
    r2.right = &r3;
    r31.right = &r1;

    assert(7 == rob(&r));
}