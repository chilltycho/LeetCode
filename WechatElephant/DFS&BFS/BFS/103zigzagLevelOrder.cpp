#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//层序，第一层左向右，第二层右向左...
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    deque<TreeNode *> mq;
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    bool isleft = true;
    mq.push_back(root);
    while (!mq.empty())
    {
        int size = mq.size();
        vector<int> temp;
        if(isleft)
        {
            for(int i=0;i<size;i++)
            {
                auto node=mq.front();
                mq.pop_front();
                temp.push_back(node->val);
                if(node->left) mq.push_back(node->left);
                if(node->right) mq.push_back(node->right);
            }
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                auto node=mq.back();
                mq.pop_back();
                temp.push_back(node->val);
                if(node->right) mq.push_front(node->right);
                if(node->left) mq.push_front(node->left);
            }
        }
        res.push_back(temp);
        isleft=!isleft;
    }
    return res;
}

int main()
{
    TreeNode root(3);
    TreeNode nine(9);
    TreeNode twenty(20);
    TreeNode seven(7);
    TreeNode fifteen(15);
    root.left = &nine;
    root.right = &twenty;
    root.right->left = &fifteen;
    root.right->right = &seven;
    auto vii = zigzagLevelOrder(&root);
    for (auto c : vii)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}