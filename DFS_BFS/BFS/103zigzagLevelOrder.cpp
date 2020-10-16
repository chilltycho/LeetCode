#include "../TreeNode.h"
#include <deque>
using namespace std;
//层序，第一层左向右，第二层右向左...
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
        if (isleft)
        {
            for (int i = 0; i < size; i++)
            {
                auto node = mq.front();
                mq.pop_front();
                temp.push_back(node->val);
                if (node->left)
                    mq.push_back(node->left);
                if (node->right)
                    mq.push_back(node->right);
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                auto node = mq.back();
                mq.pop_back();
                temp.push_back(node->val);
                if (node->right)
                    mq.push_front(node->right);
                if (node->left)
                    mq.push_front(node->left);
            }
        }
        res.push_back(temp);
        isleft = !isleft;
    }
    return res;
}

int main()
{
    vector<int> vi{3, 9, 20, -1, -1, 15, 7};
    auto root=vecToTree(vi);
    auto vii = zigzagLevelOrder(root);
    for (auto c : vii)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}