/*给定二叉树，每个节点存放0-9，从根到叶子节点路径1->2->3代表123，计算从根到叶子节点生成
所有数字之和*/
#include <queue>
#include "../TreeNode.h"
using namespace std;

int helper(TreeNode *root, int temp) //dfs
{
    if (root == nullptr)
        return 0;
    temp = temp * 10 + root->val;                       //temp不能作为全局变量
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
    vector<int> vi{4, 9, 0, 5, 1};
    auto t1 = vecToTree(vi);
    cout << sumNumbers(t1);
}