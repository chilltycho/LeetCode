/*给定无向图,找出从起点到终点成功概率最大路径,返回其成功概率*/
#include <vector>
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
//Dijkstra O((V+E)logV)
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb,
                      int start, int end)
{
    vector<vector<pair<double, int>>> graph(n);//建立邻接表,无向图
    for (int i = 0; i < edges.size(); i++)
    {
        auto e = edges[i];
        graph[e[0]].emplace_back(succProb[i], e[1]);
        graph[e[1]].emplace_back(succProb[i], e[0]);
    }
    priority_queue<pair<double, int>> que;//优先队列
    vector<double> prob(n, 0);//从start到图各节点概率
    que.emplace(1, start);
    prob[start] = 1;
    while (!que.empty())
    {
        auto temp = que.top();
        auto pr = temp.first;
        auto node = temp.second;
        que.pop();
        if (pr < prob[node])
            continue;
        for (const auto next : graph[node])//遍历下个节点
        {
            auto prNext = next.first;
            auto nodeNext = next.second;
            if (prob[nodeNext] < prob[node] * prNext)//松弛
            {
                prob[nodeNext] = prob[node] * prNext;
                que.emplace(prob[nodeNext], nodeNext);
            }
        }
    }
    return prob[end];
}

int main()
{
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}}; //描述边
    vector<double> succProb{0.5, 0.5, 0.2};
    assert(0.25 == maxProbability(3, edges, succProb, 0, 2));
}