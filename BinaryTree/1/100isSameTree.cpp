#include "../TreeNode.h"
#include <cassert>
#include <queue>
using namespace std;

bool isSameTree_dfs(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr) //考虑[1,2] [1,null,2]
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree_dfs(p->left, q->left) && isSameTree_dfs(p->right, q->right);
}

bool isSameTree_bfs(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;

    queue<TreeNode *> q1, q2;
    q1.push(p);
    q2.push(q);
    while ((!q1.empty()) && (!q2.empty()))
    {
        auto n1 = q1.front();
        q1.pop();
        auto n2 = q2.front();
        q2.pop();
        if (n1->val != n2->val)
            return false;
        if ((n1->left == nullptr) ^ (n2->left == nullptr))
            return false;
        if ((n1->right == nullptr) ^ (n2->right == nullptr))
            return false;
        if (n1->left != nullptr)
            q1.push(n1->left);
        if (n2->left != nullptr)
            q2.push(n2->left);
        if (n1->right != nullptr)
            q1.push(n1->right);
        if (n2->right != nullptr)
            q2.push(n2->right);
    }
    return q1.empty() && q2.empty();
}

int main()
{
    vector<int> vi{1, 2, 3};
    auto t1 = vecToTree(vi);
    auto t2 = vecToTree(vi);
    assert(isSameTree_bfs(t1, t2));

    vector<int> v1{1, 2};
    vector<int> v2{1, -1, 2};
    auto tr1 = vecToTree(v1);
    auto tr2 = vecToTree(v2);
    assert(!isSameTree_bfs(tr1, tr2));
}