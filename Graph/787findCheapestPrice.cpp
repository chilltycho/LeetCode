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
    for (const auto &f : flights)
        adjList[f[0]].emplace_back(f[1], f[2]);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    minHeap.push({0, src, K + 1}); //cost, vertex,hops
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

int main()
{
    vector<vector<int>> edges{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(200 == findCheapestPrice(3, edges, 0, 2, 1));

    vector<vector<int>> edges1{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(500 == findCheapestPrice(3, edges1, 0, 2, 0));
}