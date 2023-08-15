## 最短路径算法
### 单源最短路
1. 不带负权边：Dijkstra，堆优化(小堆)，时间复杂度$O(VlogV+E)$，可处理环
2. 带负权边：Bellman-Ford,$O(VE)$ SPFA,$O(E)$
### 多源最短路
Floyd 动态规划，$O(V^3)$

```C++
/**用于求单源到其他节点最短路径,times:{u,w,v}起点,终点,权值
 * 不断探测相邻点
*/
void Dijkstra(vector<vector<int>> times,int start)
{
    unordered_map<int,vector<pair<int,int>>> graph;//邻接表 起点:终点,权值
    for(const auto &t:times)
        graph[t[0]].emplace_back(t[1],t[2]);
    //最小堆 权值:终点
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
    minHeap.emplace(0,start);//起点到起点权值为0
    while(!minHeap.empty())
    {
        auto temp = minHeap.top();
        minHeap.pop();
        auto weight = temp[0];
        auto node = temp[1];
        for(const auto& next:graph[node]) // 下个节点
        {
            minHeap.emplace(weight+next.second,next.first);
        }
    }
}

// 通过N次迭代，找到从源点到终点不超过N条边构成的最短路路径。
void bellman-ford(vector<vector<int>> &times, int N, int K)
{
    vector<int> dist(N + 1, INT8_MAX);
    dist[K] = 0;
    for (int i = 0; i < N; i++)
    {
        for (const auto &e : times)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INT8_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    int maxwait = 0;
    for (int i = 1; i <= N; i++)
        maxwait = max(maxwait, dist[i]);
    return maxwait == INT8_MAX ? -1 : maxwait;
}
```