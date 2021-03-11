/*先序遍历，中序遍历，后序遍历迭代法*/
#include "../BinaryTree/TreeNode.h"
#include <algorithm>
using namespace std;

// 根左右, 每次先处理中间节点，然后将右孩子加入栈，再加入左孩子
vector<int> preorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    auto rt = root;
    while (rt || st.size())
    {
        while (rt)
        {
            res.push_back(rt->val);// 一直向左走，把当前值记录，把右节点入栈
            st.push(rt->right);
            rt = rt->left;
        }
        rt = st.top();
        st.pop();
    }
    return res;
}

// 左根右
vector<int> inorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    auto rt = root;
    while (rt || st.size())
    {
        if (rt)
        {
            st.push(rt); 
            rt = rt->left;
        }
        else
        {
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            rt = node->right;
        }
    }
    return res;
}

// 左右根
vector<int> postorder(TreeNode *root)
{
    stack<TreeNode *> stk;
    auto rt = root;
    vector<int> res;
    while (rt || stk.size())
    {
        while (rt)
        {
            res.push_back(rt->val);
            stk.push(rt->left);
            rt = rt->right;
        }
        rt = stk.top();
        stk.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    auto root = vecToTree(vi);
    auto re = postorder(root);
    for (auto c : re)
        cout << c << ' ';
    cout << endl;
}