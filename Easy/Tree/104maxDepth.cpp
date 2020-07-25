//求树深度
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int maxDepth_dfs(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    return max(maxDepth_dfs(root->left),maxDepth_dfs(root->right))+1;
}

int maxDepth_bfs(TreeNode* root)
{
    queue<TreeNode*> q;
    int ans=0;
    if(root!=nullptr)
        q.push(root);
    while(!q.empty())
    {
        for(int i=q.size()-1;i>=0;--i)
        {
            auto cur=q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        ++ans;
    }
    return ans;
}