//给定平面上点组成列表points。找出K个距离原点(0,0)最近的点
#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <vector>
using namespace std;
//直接排序Onlog(n)
vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
  sort(points.begin(), points.end(),
       [](const vector<int> &a, const vector<int> &b) {
         return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
       });
  return {points.begin(), points.begin() + K};
}

//堆排序
vector<vector<int>> kClosest_1(vector<vector<int>> &points, int K) {
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < K; ++i)
    pq.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
  for (int i = K; i < points.size(); i++) {
    int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    if (dist < pq.top().first) {
      pq.pop();
      pq.emplace(dist, i);
    }
  }
  vector<vector<int>> res;
  while (!pq.empty()) {
    res.push_back(points[pq.top().second]);
    pq.pop();
  }
  return res;
}

//快速排序，快速排序每次将数组分成两部分，小于pivot元素放到左侧，大于的放到右侧
void random_select(vector<vector<int>> &points, int left, int right, int K) {
  mt19937 gen{random_device{}()};
  int pivot_id = uniform_int_distribution<int>{left, right}(gen);
  int pivot = points[pivot_id][0] * points[pivot_id][0] +
              points[pivot_id][1] * points[pivot_id][1];
  swap(points[right], points[pivot_id]);
  int i = left - 1;
  for (int j = left; j < right; ++j) {
    int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
    if (dist <= pivot) {
      i++;
      swap(points[i], points[j]);
    }
  }
  ++i;
  swap(points[i], points[right]);
  if (K < i - left + 1)
    random_select(points, left, i - 1, K);
  else if (K > i - left + 1)
    random_select(points, i + 1, right, K - (i - left + 1));
}

vector<vector<int>> kClosest_2(vector<vector<int>> &points, int K) {
  int n = points.size();
  random_select(points, 0, n - 1, K);
  return {points.begin(), points.begin() + K};
}

int main() {
  vector<vector<int>> points{{1, 3}, {-2, 2}};
  auto res = kClosest(points, 1);
  for (auto &c : res) {
    for (auto &cc : c)
      cout << cc << ' ';
    cout << endl;
  }
}

