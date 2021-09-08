#include "TreeNode.h"
using namespace std;
// 仅一次push_back

/*先序，根左右。迭代算法中，每到一个节点，应立即访问。
在A的两颗子树中，遍历完左子树后，再遍历右子树。因此，遍历左子树前，将右子树压栈*/
vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> res;
    TreeNode *rt = root;
    while (rt || stk.size())
    {
        while (rt)
        {
            stk.push(rt->right);    //右节点压栈
            res.push_back(rt->val); //访问p节点
            rt = rt->left;
        }
        rt = stk.top();
        stk.pop();
    }
    return res;
}
/*后序遍历，左右根。先根右左，再逆序*/
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> stk;
    TreeNode *rt = root;
    while (rt || !stk.empty())
    {
        while (rt)
        {
            stk.push(rt->left);
            res.push_back(rt->val);
            rt = rt->right;
        }
        rt = stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
/*中序遍历：左根右*/
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> res;
    TreeNode *rt = root;
    while (rt || stk.size())
    {
        // 不断往左子树走，每走一次将当前节点保存到栈中，模拟递归
        while (rt)
        {
            stk.push(rt);
            rt = rt->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    auto root = vecToTree(vi);
    auto res = preorderTraversal(root);
    for (auto c : res)
    {
        cout << c << ' ';
    }
    cout << endl;
    preprint(root);
}