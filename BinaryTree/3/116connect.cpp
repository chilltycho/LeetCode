/*给定完美二叉树，每个父节点有两个子节点。填充next为右侧节点，若没有则null*/
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x):val(x),left(nullptr),right(nullptr),next(nullptr){}
};
//要求常量空间，不能使用bfs
Node *connect(Node *root)
{
    if(root==nullptr)
        return root;
    if(root->left!=nullptr)
        root->left->next=root->right;//node左子节点next为node右子节点
    if(root->right!=nullptr)
        root->right->next=root->next!=nullptr?root->next->left:nullptr;//node右子节点next为node->next左子节点
    connect(root->left);
    connect(root->right);
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

    r.left=&n2;
    r.right=&n3;
    n2.left=&n4;
    n2.right=&n5;
    n3.left=&n6;
    n3.right=&n7;
}