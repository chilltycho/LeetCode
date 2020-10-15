#include "TreeNode.h"
using namespace std;
int pre = -1;
void dfs(TreeNode *root) //前序
{
    if (root == nullptr)
        return;
    dfs(root->left);
    cout << pre << ' ' << root->val << endl;
    pre = root->val;
    dfs(root->right);
}

int main()
{
    vector<int> vi{1, 1};
    dfs(vecToTree(vi));
}