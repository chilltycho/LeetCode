## 最短路径算法
### 单源最短路
1. 不带负权边：Dijkstra，堆优化(小堆)，时间复杂度$O(VlogV+E)$，可处理环
2. 带负权边：Bellman-Ford,$O(VE)$ SPFA,$O(E)$
### 多源最短路
Floyd 动态规划，$O(V^3)$ 适合负权图

```C++
// 743题为例

// Floyd
int floyd(vector<vector<int>>& times, int start, int n) {
    int w[n+1][n+1];
    // 初始化
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            w[i][j]=w[j][i]=i==j?0:INT8_MAX;
        }
    }

    for(auto t:times) {
        w[t[0]][t[1]]=t[2];
    }

    // 三层循环：枚举中转点-起点-终点
    for(int p = 1; p <= n; p++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
            }
        }
    }

    int res=0;
    for(int i=1;i<=n;i++) {
        res=max(res,w[start][i]);
    }
    return res==INT8_MAX?-1:res;
}

/**用于求单源到其他节点最短路径,times:{u,w,v}起点,终点,权值
 * 不断探测相邻点
*/
void Dijkstra(vector<vector<int>>& times,int start)
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

// 通过N次迭代(走n步)，找到从源点到终点不超过N条边构成的最短路路径。
void bellman_ford(vector<vector<int>> &times, int N, int start)
{
    // 起点到其他点权值
    vector<int> dist(N + 1, INT8_MAX);
    // 起点到起点权值
    dist[start] = 0;
    for (int i = 0; i < N; i++) {
        for (const auto &e : times) {
            // 起点、终点、权值
            int u = e[0], v = e[1], w = e[2];
            // dist[u] != INT8_MAX意味着从起点开始，类似BFS
            if (dist[u] != INT8_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    int maxwait = 0;
    for (int i = 1; i <= N; i++) {
        maxwait = max(maxwait, dist[i]);
    }
    return maxwait == INT8_MAX ? -1 : maxwait;
}

// SPFA邻接表，可认为是Bellman的优化
```
