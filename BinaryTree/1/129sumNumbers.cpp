/*给定二叉树，每个节点存放0-9，从根到叶子节点路径1->2->3代表123，计算从根到叶子节点生成
所有数字之和*/
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int helper(TreeNode *root, int i) //dfs
{
    if (root == nullptr)
        return 0;
    int temp = i * 10 + root->val;                       //temp不能作为全局变量
    if (root->left == nullptr && root->right == nullptr) //到达叶子节点时返回
        return temp;
    return helper(root->left, temp) + helper(root->right, temp);
}

int sumNumbers(TreeNode *root)
{
    return helper(root, 0);
}

int sumNumbers_1(TreeNode *root) //bfs
{
    if (root == nullptr)
        return 0;
    vector<int> nums;
    queue<TreeNode *> mqnode;
    queue<int> mqnums;
    mqnums.push(root->val);
    mqnode.push(root);
    while (!mqnode.empty())
    {
        auto node = mqnode.front();
        int temp = mqnums.front();
        mqnode.pop();
        mqnums.pop();
        if (node->left == nullptr && node->right == nullptr)
            nums.push_back(temp);
        if (node->left != nullptr)
        {
            mqnums.push(temp * 10 + node->left->val);
            mqnode.push(node->left);
        }
        if (node->right != nullptr)
        {
            mqnums.push(temp * 10 + node->right->val);
            mqnode.push(node->right);
        }
    }
    int sum = 0;
    for (auto c : nums)
        sum += c;
    return sum;
}

int main()
{
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n5(5);
    TreeNode n1(1);
    TreeNode n0(0);

    TreeNode p(4);
    p.left = &n9;
    p.right = &n0;
    n9.left = &n5;
    n9.right = &n1;

    cout << sumNumbers(&p);
}