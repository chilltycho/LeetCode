#include <iostream>
#include <queue>
using namespace std;

//对于二叉树
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
};

void dfs(TreeNode *root) //对于树
{
    if (root == nullptr)
        return;
    dfs(root->left);
    dfs(root->right);
}

bool inArea(vector<vector<char>> grid, int r, int c)
{
    return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
}

void dfs(vector<vector<int>> &grid, int r, int c)
{
    if (!inArea(grid, r, c))
        return;
    grid[r][c] = 2; //已经遍历过，防止陷入重复遍历，如全为1
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

void dfs(vector<vector<char>> &grid, int r, int c) //对网格
{
    int nr = grid.size();
    int nc = grid[0].size();
    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1')
        dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1')
        dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1')
        dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1')
        dfs(grid, r, c + 1);
}

void bfs(TreeNode *root)
{
    queue<TreeNode *> mq;
    mq.push(root);
    while (!mq.empty())
    {
        auto node = mq.front();
        mq.pop();
        if (node->left != nullptr)
            mq.push(node->left);
        if (node->right != nullptr)
            mq.push(node->right);
    }
}

void leverlorderBfs(TreeNode *root)//层序
{
    queue<TreeNode *> mq;
    mq.push(root);
    while (!mq.empty())
    {
        int size = mq.size();//注意该语句位置，放入for循环会一直变化
        for (int i = 0; i < size; i++)
        {
            auto node = mq.front();
            mq.pop();
            if (node->left != nullptr)
                mq.push(node->left);
            if (node->right != nullptr)
                mq.push(node->right);
        }
    }
}

//bfs用于最短路径
void grid_bfs(vector<vector<int>> &grid, int r, int c)
{
    int Row = grid.size();
    int Col = grid[0].size();
    queue<vector<int>> mq;
    mq.push(vector<int>{r, c});
    while (!mq.empty())
    {
        int n = mq.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> node = mq.front();
            mq.pop();
            int r = node[0];
            int c = node[1];
            if (r - 1 >= 0 && grid[r - 1][c] == 0)
            {
                grid[r - 1][c] = 2;
                mq.push(vector<int>{r - 1, c});
            }
            if (r + 1 < Row && grid[r + 1][c] == 0)
            {
                grid[r + 1][c] = 2;
                mq.push(vector<int>{r + 1, c});
            }
            if (c - 1 >= 0 && grid[r][c - 1] == 0)
            {
                grid[r][c - 1] = 2;
                mq.push(vector<int>{r, c - 1});
            }
            if (c + 1 < Col && grid[r][c + 1] == 0)
            {
                grid[r][c + 1] = 2;
                mq.push(vector<int>{r, c + 1});
            }
        }
    }
}
vector<vector<int>> moves{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool inArea(vector<vector<int>> &grid, int r, int c)
{
    return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
}
void grid_bfs(vector<vector<int>> &grid, int r, int c)
{
    queue<vector<int>> mq;
    mq.push(vector<int>{r, c});
    while (!mq.empty())
    {
        int n = mq.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> node = mq.front();
            int r = node[0];
            int c = node[1];
            mq.pop();
            for (auto move : moves)
            {
                int r2 = r + move[0];
                int c2 = c + move[1];
                if (inArea(grid, r2, c2) && grid[r2][c2] == 0)
                {
                    grid[r2][c2] = 2;
                    mq.push(vector<int>{r2, c2});
                }
            }
        }
    }
}