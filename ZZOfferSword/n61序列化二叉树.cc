#include <iostream>
#include <cstring>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

char *Serialize(TreeNode *root)
{
    if (!root)
    {
        return "#";
    }

    string res = to_string(root->val);
    res.push_back(',');

    char *left = Serialize(root->left);
    char *right = Serialize(root->right);

    char *ret = new char[strlen(left) + strlen(right) + res.size()];
    // 如果是string类型，直接用operator += ,这里char* 需要用函数
    strcpy(ret, res.c_str());
    strcat(ret, left);
    strcat(ret, right);

    return ret;
}
// 参数使用引用&， 以实现全局变量的目的
TreeNode *deseri(char *&s)
{
    if (*s == '#')
    {
        ++s;
        return nullptr;
    }

    // 构造根节点值
    int num = 0;
    while (*s != ',')
    {
        num = num * 10 + (*s - '0');
        ++s;
    }
    ++s;
    // 递归构造树
    TreeNode *root = new TreeNode(num);
    root->left = deseri(s);
    root->right = deseri(s);

    return root;
}

TreeNode *Deserialize(char *str)
{
    return deseri(str);
}
