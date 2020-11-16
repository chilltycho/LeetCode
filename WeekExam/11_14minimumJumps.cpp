#include <vector>
#include <cassert>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
vector<int> visited;
int cnt = 1000000;
void dfs(int x, int a, int b, int count, int t)
{
    if (x == 0)
    {
        cnt = min(cnt, count);
        return;
    }
    if (x - a >= 0 && visited[x - a] != 1) //从终点往前
    {
        visited[x - a] = 1;
        dfs(x - a, a, b, count + 1, 0);
        visited[x - 1] = 0;
    }
    if (x + b < 6002 && visited[x + b] != 1 && t == 0)
    {
        visited[x + b] = 1;
        dfs(x + b, a, b, count + 1, 1);
        visited[x + b] = 0;
    }
}

int minimumJumps(vector<int> forbidden, int a, int b, int x)
{
    visited.resize(6002, 0);
    for (int i = 0; i < forbidden.size(); i++)
        visited[forbidden[i]] = 1;
    dfs(x, a, b, 0, 0);
    if (cnt < 1000000)
        return cnt;
    else
        return -1;
}

//bfs
struct node
{
    int i;
    bool is;
    node(int a, bool b) : i(a), is(b) {}
};

int minimumJumps_bfs(vector<int> &forbidden, int a, int b, int x)
{
    if (x == 0)
        return 0;
    vector<int> visit(4004);
    for (auto t : forbidden)
        visited[t] = 1;
    int res = 0;
    queue<node> q;
    q.push(node(0, false));
    visited[0] = 1;
    while (!q.empty())
    {
        res++;
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            auto temp = q.front();
            q.pop();
            if (temp.i + a == x)
                return res;
            else if (temp.i + a < 4004 && visited[temp.i + a] == 0)
            {
                visited[temp.i + a] = 1;
                q.push(node(temp.i + a, false));
            }
            if (temp.i - b == x)
                return res;
            else if (temp.i - b >= 0 && visited[temp.i - b] == 0 && temp.is == false)
            {
                q.push(node(temp.i - b, true));
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> forbidden{14, 4, 18, 1, 15};
    assert(3 == minimumJumps(forbidden, 3, 15, 9));
    vector<int> f2{8, 3, 16, 6, 12, 20};
    assert(-1 == minimumJumps(f2, 15, 13, 11));
}