/*对比116为一般二叉树*/
#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node *getNextNoNullChild(Node *root) //一路向右找到有子节点的根节点
{
    while (root->next != nullptr)
    {
        if (root->next->left != nullptr)
            return root->next->left;
        if (root->next->right != nullptr)
            return root->next->right;
        root = root->next;
    }
    return nullptr;
}
//要求常量空间，不能使用bfs
Node *connect(Node *root)
{
    if (root == nullptr || (root->right == nullptr && root->left == nullptr))
        return root;
    if (root->left != nullptr && root->right != nullptr)
    {
        root->left->next = root->right; //node左子节点next为node右子节点
        root->right->next = getNextNoNullChild(root);
    }
    if (root->left == nullptr)
        root->right->next = getNextNoNullChild(root);
    if (root->right == nullptr)
        root->left->next = getNextNoNullChild(root);

    root->right = connect(root->right); //先递归右子树，否则左子树到右子树无法正确挂载
    root->left = connect(root->left);
    return root;
}

int main()
{
    Node r(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(7);
    Node n7(7);

    r.left = &n2;
    r.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
}