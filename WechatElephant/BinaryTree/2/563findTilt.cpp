/*节点的坡度定义为该节点左子树的节点之和和右子树节点之和的差的绝对值。空节点的坡度是0。*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr){}
};

int titlt;

int dfs(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftt = dfs(root->left);
    int rightt = dfs(root->right);
    titlt += abs(leftt - rightt);
    return root->val + leftt + rightt;
}

int findTilt(TreeNode *root)
{
    titlt = 0;
    dfs(root);
    return titlt;
}

int main()
{
    TreeNode root(1);
    TreeNode n2(2);
    TreeNode n3(3);

    root.left=&n2;
    root.right=&n3;

    cout<<findTilt(&root);
}