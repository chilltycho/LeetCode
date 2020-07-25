#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode **rootp, int val)
{
    auto newnode = new TreeNode(val);
    if (*rootp == nullptr)
    {
        *rootp = newnode;
        return;
    }
    else
    {
        if (val < (*rootp)->val)
            insert(&(*rootp)->left, val);
        else if (val > (*rootp)->val)
            insert(&(*rootp)->right, val);
        else
            return;
    }
}

void printtree(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << ' ';
        printtree(root->left);
        printtree(root->right);
    }
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
}
int maxDepth_bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    int ans = 0;
    if (root != nullptr)
        q.push(root);
    while (!q.empty())
    {
        for (int i = q.size() - 1; i >= 0; --i)
        {
            auto cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        ++ans;
    }
    return ans;
}

bool isValidBST(TreeNode* root)
{
    queue<TreeNode *> q;
    if (root == nullptr)
        return true;
    q.push(root);
    while (!q.empty())
    {
        for (int i = q.size() - 1; i >= 0; --i)
        {
            auto cur = q.front();
            q.pop();
            if (cur->left&&cur->left->val>=cur->val)
                return false;
            else if(cur->left)
                q.push(cur->left);
            if (cur->right&&cur->right->val<=cur->val)
                return false;
            else if(cur->right)
                q.push(cur->right);
        }
    }
    return true;
}

int main()
{
    TreeNode *proot = nullptr;
    insert(&proot, 5);
    insert(&proot, 1);
    insert(&proot, 3);
    insert(&proot, 2);
    insert(&proot, 0);
    insert(&proot, 8);
    insert(&proot, 7);
    insert(&proot, 9);
    //printtree(proot);
    cout<<isValidBST(proot);

    TreeNode *pro=nullptr;
    insert(&pro,10);
    insert(&pro,5);
    insert(&pro,3);
    cout<<isValidBST(pro);
}   