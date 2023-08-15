/*给定无向图,找出从起点到终点成功概率最大路径,返回其成功概率*/
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Dijkstra O((V+E)logV)
double maxProbability(int n, vector<vector<int>> &edges,
                      vector<double> &succProb, int start, int end) {
  //邻接表 起点:权值 终点
  vector<vector<pair<double, int>>> graph(n);
  for (int i = 0; i < edges.size(); i++) {
    auto e = edges[i];
    graph[e[0]].emplace_back(succProb[i], e[1]);
    graph[e[1]].emplace_back(succProb[i], e[0]);
  }
  //最大堆 权值,终点
  priority_queue<pair<double, int>> que;
  vector<double> prob(n, 0); //从start到图各节点概率
  que.emplace(1, start);     // 概率，起点
  prob[start] = 1;           //起点到起点概率为1
  vector<bool> isvis(n, false);
  while (!que.empty()) {
    auto cur = que.top();
    auto cur_pr = cur.first;
    auto cur_pos = cur.second;
    que.pop();
    if (isvis[cur_pos])
      continue;

    isvis[cur_pos] = true;
    if (cur_pos == end)
      return cur_pr;
    //遍历下个节点
    for (const auto next : graph[cur_pos]) {
        auto next_pr = next.first;
        auto next_pos = next.second;
        if (isvis[next_pos])
          continue;
        if (prob[next_pos] < prob[cur_pos] * next_pr) //松弛
        {
          prob[next_pos] = prob[cur_pos] * next_pr;
          que.emplace(prob[next_pos], next_pos);
        }
      }
  }
  return 0;
}
// bellman
double maxProbability(int n, vector<vector<int>> &edges,
                      vector<double> &succProb, int start, int end) {
  vector<double> dp(n, 0);
  dp[start] = 1;
  while (true) {
    bool k = false;
    for (int j = 0; j < edges.size(); ++j) {
      if (dp[edges[j][0]] * succProb[j] > dp[edges[j][1]]) {
        dp[edges[j][1]] = dp[edges[j][0]] * succProb[j];
        k = true;
      }
      if (dp[edges[j][1]] * succProb[j] > dp[edges[j][0]]) {
        dp[edges[j][0]] = dp[edges[j][1]] * succProb[j];
        k = true;
      }
    }
    if (!k)
      break;
  }
  return dp[end];
}

int main() {
  vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}}; //描述边
  vector<double> succProb{0.5, 0.5, 0.2};
  assert(0.25 == maxProbability(3, edges, succProb, 0, 2));
}