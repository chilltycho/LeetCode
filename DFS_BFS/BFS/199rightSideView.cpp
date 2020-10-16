#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//站在树右侧，从上到下看到的节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    queue<TreeNode *> mq;
    mq.push(root);
    while (!mq.empty())
    {
        int n = mq.size();
        auto node = mq.back();
        res.push_back(node->val);
        for (int i = 0; i < n; i++)
        {
            node = mq.front(); //注意这一步，应从头一个一个删除
            mq.pop();
            if (node->left != nullptr)
                mq.push(node->left);
            if (node->right != nullptr)
                mq.push(node->right);
        }
    }
    return res;
}
//深度优先搜索:根->右->左,每层访问第一个节点一定在最右边
vector<int> res;
void dfs(TreeNode *root, int depth)
{
    if (root == nullptr)
        return;
    if (depth == res.size())
        res.push_back(root->val);
    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
}

vector<int> rightSideView_1(TreeNode *root)
{
    dfs(root, 0);
    return res;
}


int main()
{
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(3);
    TreeNode t3(4);
    root.left = &t1;
    root.right = &t2;
    root.left->left = &t3;
    auto vii = rightSideView_1(&root);
    for (auto c : vii)
    {
        cout << c << ' ';
    }
}