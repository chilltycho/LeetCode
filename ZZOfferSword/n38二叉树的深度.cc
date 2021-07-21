#include "TreeNode.h"
#include<iostream>
using namespace std;
int TreeDepth(TreeNode *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
}