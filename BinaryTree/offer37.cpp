//将[1,2,3,null,null,4,5]反序列化为树。
#include "TreeNode.h"
#include <sstream>
using namespace std;
//bfs
string serialize(TreeNode *root)
{
    ostringstream out;
    queue<TreeNode *> mq;
    mq.push(root);
    while (!mq.empty())
    {
        auto temp = mq.front();
        mq.pop();
        if (temp)
        {
            out << temp->val << " ";
            mq.push(temp->left);
            mq.push(temp->right);
        }
        else
            out << "null ";
    }
    return out.str();
}

TreeNode *deserialize(string data)
{
    istringstream input(data);
    string val;
    vector<TreeNode *> res;
    while (input >> val)
    {
        if (val == "null")
            res.push_back(nullptr);
        else
            res.push_back(new TreeNode(stoi(val)));
    }
    int j = 1; //i每往后移动一位，j移动两位，j始终是当前i左子下标
    for (int i = 0; j < res.size(); i++)
    {
        if (res[i] == nullptr)
            continue;
        if (j < res.size())
            res[i]->left = res[j++];
        if (j < res.size())
            res[i]->right = res[j++];
    }
    return res[0];
}

//dfs
string serialize_dfs(TreeNode *root)
{
    if (root == nullptr)
        return "#";
    return root->val + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode *dfs(queue<string> mq)
{
    string sVal = mq.front();
    mq.pop();
    if (sVal == "#")
        return nullptr;
    auto root = new TreeNode(stoi(sVal));
    root->left = dfs(mq);
    root->right = dfs(mq);
    return root;
}

int main()
{
    vector<int> vi{1, 2, 3, -1, -1, 4, 5};
    auto root = vecToTree(vi);
    auto res = serialize(root);
    auto t1 = deserialize(res);
    preprint(t1);
}