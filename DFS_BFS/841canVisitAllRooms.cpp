#include <vector>
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
//从房间0开始，拿钥匙，判断是否能去每个房间。相当于有向图，判断是否有孤立节点。

vector<int> vis;
int num;
void dfs(vector<vector<int>> &rooms, int x)
{
    vis[x] = true;
    num++;
    for (auto &it : rooms[x])
    {
        if (!vis[it])
            dfs(rooms, it);
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    if (rooms.empty())
        return true;
    num = 0;
    auto n = rooms.size();
    vis.resize(n);
    dfs(rooms, 0);
    return num == n;
}

bool canVisitAllRooms_bfs(vector<vector<int>> &rooms)
{
    if (rooms.empty())
        return true;
    auto n = rooms.size();
    num = 0;
    queue<int> mq;
    vis.resize(n);
    vis[0] = true;
    mq.push(0);
    while (!mq.empty())
    {
        auto x = mq.front();
        mq.pop();
        num++;
        for (auto &it : rooms[x])
        {
            if (!vis[it])
            {
                vis[it] = true;
                mq.push(it);
            }
        }
    }
    return num == n;
}

int main()
{
    vector<vector<int>> vi{{1}, {2}, {3}, {}};
    assert(true == canVisitAllRooms(vi));
    vector<vector<int>> vi1{{1, 3}, {3, 0, 1}, {2}, {0}};
    assert(false == canVisitAllRooms(vi1));
}