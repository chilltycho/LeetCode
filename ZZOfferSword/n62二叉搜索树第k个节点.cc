#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

int m;
TreeNode *ans;
void dfs(TreeNode *p)
{
    if (!p || m < 1)
        return;   //不满足条件直接返回NULL/每次递归出口：
    dfs(p->left); //走到了最左边结点,到空不继续递归，该节点左右走完了回溯上一层
    if (m == 1)
        ans = p; //最左边结点 / m-到1的时候，当前结点就是第m小
    if (--m > 0)
        dfs(p->right); // 右子树同样处理/遍历该节点的右节点 (左中右)
}
TreeNode *KthNode(TreeNode *pRoot, int k)
{
    ans = nullptr;
    m = k;
    dfs(pRoot);
    return ans;
}