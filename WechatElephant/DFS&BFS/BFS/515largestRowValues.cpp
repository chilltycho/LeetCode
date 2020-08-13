#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//找到每行中最大的数
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> largestValues(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    deque<TreeNode *> mq;
    mq.push_back(root);
    while (!mq.empty())
    {
        int maxval = INT_MIN;
        int n = mq.size();
        for (int i = 0; i < n; i++)
        {
            auto node = mq.front();
            maxval = max(node->val, maxval);
            mq.pop_front();
            if (node->left != nullptr)
                mq.push_back(node->left);
            if (node->right != nullptr)
                mq.push_back(node->right);
        }
        res.push_back(maxval);
    }
    return res;
}

vector<int> res;
void dfs(TreeNode *root, int depth)
{
    if (root == nullptr)
        return;
    if (depth == res.size())//总是将到达新层第一个元素保存
        res.push_back(root->val);
    else
    {
        res[depth] = max(root->val, res[depth]);//同层元素更新
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
vector<int> largestValues_1(TreeNode *root)
{
    dfs(root,0);
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
    auto vii = largestValues_1(&root);
    for (auto c : vii)
    {
        cout << c << ' ';
    }
}