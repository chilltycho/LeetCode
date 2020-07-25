/*给定二叉树，返回所有从根节点到叶子节点的路径*/
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

void construct(TreeNode *root, string path, vector<string> &paths)
{
    if (root != nullptr)
    {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) //叶子节点
            paths.push_back(path);
        else
        {
            path += "->";
            construct(root->left, path, paths);
            construct(root->right, path, paths);
        }
    }
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    string emp = "";
    construct(root, emp, res);
    return res;
}

vector<string> binaryTreePaths_1(TreeNode *root) //bfs
{
    vector<string> paths;
    if (root == nullptr)
        return paths;
    queue<TreeNode *> node_stack;
    queue<string> path_stack;
    node_stack.push(root);
    path_stack.push(to_string(root->val));
    while (!node_stack.empty())
    {
        auto node = node_stack.front();
        auto path = path_stack.front();
        node_stack.pop();
        path_stack.pop();
        if (node->left == nullptr && node->right == nullptr)
            paths.push_back(path);
        if (node->left != nullptr)
        {
            node_stack.push(node->left);
            path_stack.push(path + "->" + to_string(node->left->val));
        }
        if (node->right != nullptr)
        {
            node_stack.push(node->right);
            path_stack.push(path + "->" + to_string(node->right->val));
        }
    }
    return paths;
}

int main()
{
    TreeNode n9(9);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n5(5);
    TreeNode n0(0);

    TreeNode p(1);
    p.left = &n2;
    p.right = &n3;
    n2.right = &n5;

    auto res = binaryTreePaths_1(&p);
    for (auto c : res)
        cout << c << ' ';
}