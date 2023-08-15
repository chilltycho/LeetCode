/*n个城市通过m个航班,从u开始,以价格w抵达v.找到从src到dst最多经过k站中转的最便宜价格,
若没有,输出-1*/
#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/**Bellman Ford 求src到dst的1到K个航班成本的总和的最小值
 * d[v] = d[u] + w(u,v) 到v最短距离。动态规划
 */
int findCheapestPrice_1(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
  // 经过i次迭代，到达dst最短距离
  vector<vector<long>> dp(n, vector<long>(K + 1, INT32_MAX));
  K = min(K, n - 2);
  dp[src][0] = 0;
  for (auto f : flights) {
    auto start = f[0];
    auto end = f[1];
    long cost = f[2];
    if (start == src)
      dp[end][0] = min(dp[end][0], cost);
  }

  for (int i = 1; i <= K; i++) {
    for (auto f : flights) {
      int fsrc = f[0];
      int fdst = f[1];
      long cost = f[2];
      dp[fdst][i] =
          min(min(dp[fdst][i - 1], dp[fdst][i]), dp[fsrc][i - 1] + cost);
    }
  }
  return dp[dst][K] == INT32_MAX ? -1 : dp[dst][K];
}
// 无法使用Dijkstra了，存在环
int findCheapestPrice1(int n, vector<vector<int>> &flights, int src, int dst,
                       int k) {
  unordered_map<int, vector<pair<int, int>>> adjList;
  vector<int> weights(n, INT_MAX);
  vector<bool> visited(n, false);
  // 邻接表，起点：终点，花费
  for (const auto &f : flights)
    adjList[f[0]].emplace_back(f[1], f[2]);
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
      minHeap;
  minHeap.push({0, src, k + 1}); //花费，起点，站数
  int res = INT_MAX;
   while (!minHeap.empty()) {
    auto cur = minHeap.top();
    minHeap.pop();
    auto cur_w = cur[0];
    auto cur_pos = cur[1];
    auto stop_num = cur[2];
    if(visited[cur_pos]){
        continue;
    }
    visited[cur_pos]=true;
    if (cur_pos == dst)
      res = min(res,cur_w);
    // cout << cur[0] << ' ' << cur[1] << ' ' << cur[2] << endl;
    if (stop_num > 0) {
      for (const auto &next : adjList[cur_pos]) {
        int next_pos = next.first;
        int next_w = next.second;
        int next_cost = cur_w + next_w;
        minHeap.push({next_cost, next_pos, stop_num - 1});
      }
    }
  }
  return res==INT_MAX?-1:res;
}

int main() {
    vector<vector<int>> edges{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(200 == findCheapestPrice1(3, edges, 0, 2, 1));

    vector<vector<int>> edges1{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(500 == findCheapestPrice1(3, edges1, 0, 2, 0));

  // 7
  vector<vector<int>> edges2{{0, 1, 5}, {1, 2, 5}, {0, 3, 2},
                             {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
  cout << findCheapestPrice1(5, edges2, 0, 2, 2) << endl;

  // 11
    vector<vector<int>> edges3{{0, 3, 3},   {3, 4, 3},  {4, 1, 3},   {0, 5,
    1},
                               {5, 1, 100}, {0, 6, 2},  {6, 1, 100}, {0, 7,
                               1}, {7, 8, 1},   {8, 9, 1},  {9, 1, 1},   {1,
                               10, 1}, {10, 2, 1},  {1, 2, 100}};
    cout << findCheapestPrice1(13, edges3, 0, 2, 4) << endl;

  //   // -1
    vector<vector<int>> edges4{
        {11, 12, 74}, {1, 8, 91},  {4, 6, 13},   {7, 6, 39},  {5, 12, 8},
        {0, 12, 54},  {8, 4, 32},  {0, 11, 4},   {4, 0, 91},  {11, 7, 64},
        {6, 3, 88},   {8, 5, 80},  {11, 10, 91}, {10, 0, 60}, {8, 7, 92},
        {12, 6, 78},  {6, 2, 8},   {4, 3, 54},   {3, 11, 76}, {3, 12, 23},
        {11, 6, 79},  {6, 12, 36}, {2, 11, 100}, {2, 5, 49},  {7, 0, 17},
        {5, 8, 95},   {3, 9, 98},  {8, 10, 61},  {2, 12, 38}, {5, 7, 58},
        {9, 4, 37},   {8, 6, 79},  {9, 0, 1},    {2, 3, 12},  {7, 10, 7},
        {12, 10, 52}, {7, 2, 68},  {12, 2, 100}, {6, 9, 53},  {7, 4, 90},
        {0, 5, 43},   {11, 2, 52}, {11, 8, 50},  {12, 4, 38}, {7, 9, 94},
        {2, 7, 38},   {3, 7, 88},  {9, 12, 20},  {12, 0, 26}, {10, 5, 38},
        {12, 8, 50},  {0, 2, 77},  {11, 0, 13},  {9, 10, 76}, {2, 6, 67},
        {5, 6, 34},   {9, 7, 62},  {5, 3, 67}};
    cout << findCheapestPrice1(13, edges4, 10, 1, 10);
}
