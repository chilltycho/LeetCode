## 
递归本质：将问题分解为子问题，递归有两个要点：
1. 反复调用自身：递归调用自己两个子树
2. 终止条件：在叶结点终止递归

## 二叉树遍历中的全局变量
二叉树遍历中的全局变量。

### 二叉树的直径
二叉树的直径是任意两个节点之间的路径长度中的最大值，这条路径可能不经过根节点。
### 分解为子问题
二叉树最长路径 = max（`左子树的最长路径`，`右子树的最长路径`，`经过根节点的最长路径`）其中`左子树和右子树的最长路径都可递归求解`，__根节点的最长路径=左子树深度+右子树深度__，  

两个子问题：子树的最大直径、子树的最大深度，是否要遍历两次？只需返回两个值即可。__既然始终都是求最大值，只需全局变量保存__
```python
def dfs(root):
    if root is None
        return (0,0)
    left_depth, left_diam = dfs(root.left)
    right_depth, right_diam = dfs(root.right)
    depth = 1 + max(left_depth, right_depth)
    diam = max(left_diam, right_diam, left_depth + right_depth)
    return depth, diam

def diameterOfBinaryTree(root):
    depth, diam = dfs(root)
    return diam
```
```C++
int diameter;

int dfs(TreeNode* root)
{
    if(!root)
        return 0;
    int l = dfs(root->left);  // 左子树深度
    int r = dfs(root->right); // 右子树深度
    diameter = max(diameter, l + r);
    return 1 + max(l, r); 
}

int diameterOfBinaryTree(TreeNode* root)
{
    diameter = 0;
    dfs(root);
    return diameter;
}
```
### 二叉树最大路径和
给定二叉树，计算最大路径和。每条路径至少包含一个节点，可能不经过根节点，可能有负数。
__二叉树最大路径和 = max(左子树最大路径和，右子树最大路径和，左子树最大路径和+根节点+右子树最大路径和)__
```C++
int res=0;

int dfs(TreeNode *root)
{
    if(!root)
        return 0;
    int l = max(root->left);
    int r = max(root->right);
    int maxPathSum = root->val + max(0, l) + max(0, r);
    res = max(l, maxPathSum);
    return root->val + max(0, max(l, r));
}

int maxPathSUm(TreeNode *root)
{
    dfs(root);
    return res;
}
```
### 判断平衡二叉树
```C++
bool balanced = true;

int dfs(TreeNode *root) // 深度
{
    if(!root)
        return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    if(abs(l - r) > 1)
        balanced = false;
    return 1 + max(l,r);
}

bool isBalanced(TreeNode *root)
{
    dfs(root);
    return balanced;
}
```

## 三步法
* 拆解子问题
* 抽取全局变量
* 有几个子问题，递归函数就返回几个值

### 二叉树最长之字形路径
