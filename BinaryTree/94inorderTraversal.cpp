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
        // 不断往左子树走，每走一次将当前节点保存到栈中，模拟递归
        if (rt != nullptr)
        {
            stk.push(rt);
            rt = rt->left;
        }
        // 当前节点为空，左边走到头，从栈中弹出节点并保存，再转向右边节点，继续上面过程
        else
        {
            auto tmp = stk.top();
            res.push_back(tmp->val);
            rt = tmp->right;
        }
    }
    return res;
}

// 根左右, 每次先处理中间节点，然后将右孩子加入栈，再加入左孩子
vector<int> preorder(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> res;
    if (root == nullptr)
        return res;
    stk.push(root);
    while (stk.size())
    {
        auto node = stk.top();
        stk.pop();
        res.push_back(node->val);

        if (node->right)
            stk.push(node->right);
        if (node->left)
            stk.push(node->left);
    }
}

// 左右根
vector<int> postorder(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> res;
    if (root == nullptr)
        return res;
    stk.push(root);
    if (stk.size())
    {
        auto node = stk.top();
        stk.pop();
        res.push_back(node->val);
        if (node->left)
            stk.push(node->left);
        if (node->right)
            stk.push(node->right);
    }
    reverse(res.begin(), res.end());
    return res;
}

/**
 * 颜色标记，新节点为白色，已访问节点为灰色。
 * 若遇到白色节点，标记灰色，并将右子节点，自身，左子节点入栈。
 * 若遇到灰色节点，将节点值输出
 * */

vector<int> cinorder(TreeNode *root)
{
    int white = 0, gray = 1;
    vector<int> res;
    stack<pair<int, TreeNode *>> stk;
    stk.push(make_pair(white, root));
    while (!stk.empty())
    {
        auto color = stk.top().first;
        auto t = stk.top().second;
        stk.pop();
        if (t == nullptr)
            continue;
        if (color == white)
        {
            stk.push(make_pair(white, t->right));
            stk.push(make_pair(gray, t));
            stk.push(make_pair(white, t->left));
        }
        else
            res.push_back(t->val);
    }
    return res;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    auto root = vecToTree(vi);
    auto re = preorderTraversal(root);
    for (auto c : re)
        cout << c << endl;
}