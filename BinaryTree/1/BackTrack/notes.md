## 回溯法和遍历树所有路径
### 回溯
```C++
// 39题
vector<vector<int>> res;
vector<int> path;

void dfs(int start, int target, vector<int> &candidates)
{
    if (target == 0)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
    {
        path.push_back(candidates[i]);
        dfs(i, target - candidates[i], candidates);
        path.pop_back();
    }
}
```
### 遍历树所有路径
```C++
// 257, path未设成全局变量。
void dfs(TreeNode *root, string path, vector<string> &paths)
{
    if(root == nullptr)
        return;
    path += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) //叶子节点
        paths.push_back(path); // 不return
    else
    {
        path += "->";
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
    }
}
```