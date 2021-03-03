/*n个城市通过m个航班,从u开始,以价格w抵达v.找到从src到dst最多经过k站中转的最便宜价格,
若没有,输出-1*/
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cassert>
using namespace std;
//Dijkstra
int findCheapestPrice(int n, vector<vector<int>> &flights, int src,
                      int dst, int K)
{
    unordered_map<int, vector<pair<int, int>>> adjList;
    // 邻接表，起点：终点，花费
    for (const auto &f : flights)
        adjList[f[0]].emplace_back(f[1], f[2]);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    minHeap.push({0, src, K + 1}); //花费，起点，站数
    while (!minHeap.empty())
    {
        auto t = minHeap.top();
        minHeap.pop();
        auto cost = t[0];
        auto curr = t[1];
        auto stop = t[2];
        if (curr == dst)
            return cost;
        if (stop > 0)
        {
            for (const auto &next : adjList[curr])
                minHeap.push({cost + next.second, next.first, stop - 1});
        }
    }
    return -1;
}

/**Bellman Ford 求src到dst的1到K个航班成本的总和的最小值
 * d[v] = d[u] + w(u,v) 到v最短距离。动态规划
*/
int findCheapestPrice_1(int n, vector<vector<int>> &flights, int src,
                        int dst, int K)
{
    // 经过i次迭代，到达dst最短距离
    vector<vector<long>> dp(n, vector<long>(K + 1, INT32_MAX));
    K = min(K, n - 2);
    dp[src][0] = 0;
    for (auto f : flights)
    {
        auto start = f[0];
        auto end = f[1];
        long cost = f[2];
        if (start == src)
            dp[end][0] = min(dp[end][0], cost);
    }

    for (int i = 1; i <= K; i++)
    {
        for (auto f : flights)
        {
            int fsrc = f[0];
            int fdst = f[1];
            long cost = f[2];
            dp[fdst][i] = min(min(dp[fdst][i - 1], dp[fdst][i]), dp[fsrc][i - 1] + cost);
        }
    }
    return dp[dst][K] == INT32_MAX ? -1 : dp[dst][K];
}

int main()
{
    vector<vector<int>> edges{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(200 == findCheapestPrice(3, edges, 0, 2, 1));

    vector<vector<int>> edges1{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(500 == findCheapestPrice(3, edges1, 0, 2, 0));
}