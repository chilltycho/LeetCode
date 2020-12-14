/*先序遍历，中序遍历，后序遍历迭代法*/
#include "TreeNode.h"
#include <algorithm>
using namespace std;
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
            stk.push(rt);
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
        while (rt)
        {
            stk.push(rt);
            rt = rt->left;
        }
        rt = stk.top();
        stk.pop();
        res.push_back(rt->val);
        rt = rt->right;
    }
    return res;
}
int main()
{
    vector<int> vi{1, -1, 2, 3};
    auto root = vecToTree(vi);
    auto re = inorderTraversal(root);
    for (auto c : re)
        cout << c << endl;
}