/*给定整数n，生成所有由1..n为节点组成的二叉搜索树*/
#include "TreeNode.h"
using namespace std;

vector<TreeNode *> helper(int start, int end)
{
    vector<TreeNode *> re;
    if (start > end)
    {
        //若左子树为空，右子树不为空，要正确构建所有树，需对左右子树列表遍历
        re.push_back(nullptr);
        return re;
    }
    for (int i = start; i <= end; i++)
    {
        //TreeNode *root=new TreeNode(i);以当前root根节点的数个数num=left.size()*right.size()>1时，num颗子树共用root节点
        //获取所有可行左子树集合
        vector<TreeNode *> left = helper(start, i - 1);
        //获取所有可行右子树集合
        vector<TreeNode *> right = helper(i + 1, end);
        //从左子树集合选出一颗左子树，从右子树集合选出一颗右子树，拼接到根节点
        for (TreeNode *l : left)
        {
            for (TreeNode *r : right)
            {
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                re.push_back(root);
            }
        }
    }
    return re;
}
vector<TreeNode *> generateTrees(int n)
{
    if (n < 1)
        return vector<TreeNode *>{};
    return helper(1, n);
}

int main()
{
}