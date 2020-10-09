/*N个网络节点,标记为1到N.给定列表times,表示信号经过有向边传递时间
times[i]=(u,v,w),其中u是源节点,v是目标节点,w是从源节点到目标节点时间
从某k节点发出信号,需多届才能使所有节点都收到信号?若不能,返回-1*/
#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
#include <unordered_map>
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<int> dp; //传输时间
void dfs(int u)
{
    for (const auto &e : graph[u])
    {
        int v = e.first;       //目标点
        int w = e.second;      //从源节点传递到目标节点的时间
        if (dp[u] + w < dp[v]) //有较短路径从u到v,Dijkstra松弛操作
        {
            dp[v] = dp[u] + w;
            dfs(v);
        }
    }
}
//记录信号到达节点时间,若有的信号提前到达,则无需广播信号
int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    graph.resize(N + 1);
    dp.resize(N + 1, 101); //K最大100
    int cost = 0;
    for (auto time : times) //建立邻接表,有向图
        graph[time[0]].emplace_back(time[1], time[2]);
    dp[K] = 0; //K到K时间为0
    dfs(K);    //计算从第K个网络节点开始到各节点最短时间
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] > cost)
            cost = dp[i];
    }
    return cost == 101 ? -1 : cost;
}

//Bellman Ford
int networkDelayTime_bell(vector<vector<int>> &times, int N, int K)
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

int networkDelayTime_DijPQ(vector<vector<int>> &times, int N, int K)
{
    vector<bool> visited(N + 1, false);
    vector<int> dist(N + 1, INT8_MAX);
    //邻接表,起点:权值,终点
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto &t : times)
        graph[t[0]].emplace_back(t[2], t[1]);
    //最小堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, K});
    dist[K] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        auto cur_weight = cur.first;
        auto cur_end = cur.second;
        pq.pop();
        if (visited[cur_end])
            continue;
        visited[cur_end] = true;
        for (const auto &next : graph[cur_end])
        {
            auto next_end = next.second;
            auto next_weight = next.first;
            if (dist[next_end] > next_weight + cur_weight)
            {
                dist[next_end] = next_weight + cur_weight;
                pq.push({dist[next_end], next_end});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < dist.size(); i++)
        ans = max(dist[i], ans);
    return ans == INT8_MAX ? -1 : ans;
}

int main()
{
    vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime_DijPQ(times, 4, 2);
}