//给定非空二叉树,返回最大路径和
#include "../TreeNode.h"
using namespace std;

int res;
//返回经过root的单边分支最大和，max(root,root+left,root+right)
int dfs(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftsum = max(0, dfs(root->left));
    int rightsum = max(0, dfs(root->right));
    res = max(res, root->val + leftsum + rightsum); //left->root->right作为路径与历史最大值作比较
    return root->val + max(leftsum, rightsum);      //返回经过root的单边最大分支给上游
}

int maxValue=INT16_MIN;
int maxPathSumHelper(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    int left=maxPathSumHelper(root->left);//左子节点的值
    int right=maxPathSumHelper(root->right);//右子节点的值
    int cur=root->val+max(0,left)+max(0,right);//当前节点+左节点+右节点
    int res=root->val+max(0,max(left,right));//当前节点+一边或不加的结果
    maxValue=max(maxValue,max(cur,res));
    return res;
}

int maxPathSum(TreeNode *root)
{
    res = 0;
    dfs(root);
    return res;
}

int main()
{
    vector<int> vi{1, 2, 3};
    auto t1 = vecToTree(vi);
    cout << maxPathSum(t1) << endl;

    vector<int> vi1{-10, 9, 20, -1, -1, 15, 7};
    auto t2 = vecToTree(vi1);
    cout << maxPathSum(t2) << endl;
}