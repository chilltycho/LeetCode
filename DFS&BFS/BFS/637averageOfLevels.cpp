#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> res;
    if(root==nullptr)
        return res;
    queue<TreeNode*> mq;
    mq.push(root);
    while(!mq.empty())
    {
        int n=mq.size();
        double average=0.0;
        for(int i=0;i<n;i++)
        {
            auto node=mq.front();
            average+=node->val;
            mq.pop();
            if(node->left!=nullptr) mq.push(node->left);
            if(node->right!=nullptr) mq.push(node->right);
        }
        average/=n;
        res.push_back(average);
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
    auto vi=averageOfLevels(&root);
    for(auto c:vi)
        cout<<c<<' ';
}