/*二叉树中交错路径：选择二叉树中任意节点和一个方向（左或右），若前进方向为右，则移动到右子节点，
改变前进方向，直到无法继续移动*/
#include <iostream>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*1.子问题：二叉树最长之字形路径=max(左子树的最长之字形路径，右子树的最长之字形路径，二叉树的最长之字形根路径)
二叉树的最长之字形根路径=max(1+左子树的最长右之根路径，1+右子树的最长左之根路径)
二叉树最长左之根路径=1+左子树的最长右之根路径。
故共三个子问题：最长之字形路径，最长左之根路径，最长右之根路径
2.抽取全局变量：第一个子问题为题目要求结果，称为主要子问题，其他两个子问题是辅助子问题
判断主要子问题是否要抽取成全局变量：需要将每次计算结果汇总
3.有几个子问题，递归函数就返回几个值。第一个为全局变量，故需返回两个。*/
int res;
pair<int, int> dfs(TreeNode *root)
{
    if (root == nullptr)
        return make_pair(0, 0);
    pair<int, int> leftt = dfs(root->left);//左子树的最长之字形路径
    pair<int, int> rightt = dfs(root->right);//右子树的最长之字形路径
    int leftzz = 1 + leftt.second;//二叉树的最长左之根路径
    int rightzz = 1 + rightt.first;//二叉树的最长右之根路径
    res = max(res, leftzz);
    res = max(res, rightzz);
    return make_pair(leftzz, rightzz);//最长左之根路径长度，最长右之根路径长度
}

int longestZigZag(TreeNode *root)
{
    res = 0;
    dfs(root);
    return res - 1;
}

int main()
{
    TreeNode r(1);
    TreeNode n1(1);
    TreeNode n2(1);
    TreeNode n3(1);
    TreeNode n4(1);
    TreeNode n5(1);
    TreeNode n6(1);

    r.left = &n1;
    r.right = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    n4.right = &n6;

    cout << longestZigZag(&r);
}