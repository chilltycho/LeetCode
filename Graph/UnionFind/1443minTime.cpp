//给定编号0-n-1的树,通过一条边1s,从0出发,最少需多少秒可收集所有苹果,并回到0.
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
bool *visited;
int *m;
int result = 0;

void dfs(int i, int *m)
{
    if (i == 0 || visited[i]) // 到达根节点或到达已收集过的点
        return;
    result++;
    visited[i] = true;
    dfs(m[i], m);
}

//从子结点往父节点走,走的永远是需要的路线,以0为根节点.
int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    if (hasApple.size() < 2)
        return 0;
    visited = new bool[hasApple.size()]{false};
    m = new int[n];
    for (int i = 0; i < n; i++)
        m[i] = INT8_MIN;
    m[0] = 0;
    for (auto edge : edges) //构建树,由于无向,保证连接到已有节点下
    {
        if (m[edge[1]] == INT8_MIN)
            m[edge[1]] = edge[0];
        else
            m[edge[0]] = edge[1];
    }
    for (int i = 0; i < n; i++)
        cout << m[i] << ' ';
    for (int i = 1; i < hasApple.size(); i++)
    {
        if (hasApple[i])
            dfs(i, m);
    }
    delete[] visited;
    delete[] m;
    return result * 2;
}

int main()
{
    vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}}; //相连接的边
    vector<bool> hasApple{false, false, true, false, true, true, false};
    //assert(8 == minTime(7, edges, hasApple));
    vector<vector<int>> edges1{{0, 1}, {1, 2}, {0, 3}};
    vector<bool> hasApple1{true, true, false, true};
    cout << minTime(4, edges1, hasApple1);
}
