/*本题中,树指连通且无环的无向图,返回可删去的边,使结果图是N个节点
的树.若有多个答案,返回二维数组中最后出现的边*/
#include <cassert>
#include <vector>
using namespace std;
class UnionFind {
private:
  int *parent;

public:
  UnionFind(int n) {
    parent = new int[n];
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  bool munion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return false;
    parent[rootX] = rootY;
    return true;
  }
};

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
  int len = edges.size();
  UnionFind unionFind(len + 1);
  for (auto edge : edges) {
    bool success = unionFind.munion(edge[0], edge[1]);
    if (!success) //已经连接
      return edge;
  }
  return vector<int>{-1, -1};
}

int main() {
  vector<vector<int>> vi{{1, 2}, {1, 3}, {2, 3}};
  vector<int> res{2, 3};
  assert(res == findRedundantConnection(vi));
  vector<vector<int>> vii{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  vector<int> res1{1, 4};
  assert(res1 == findRedundantConnection(vii));
}