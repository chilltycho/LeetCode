/*给定Ｎ＊Ｎ矩阵Ｍ，表示朋友间关系，若Ｍ[i][i]=1,表示i,j为朋友关系
输出朋友圈总数,朋友关系具有传递性*/
#include <cassert>
#include <vector>
using namespace std;

class UnionFind {
private:
  int count;
  int *parent;
  int *rank;

public:
  UnionFind(int n) {
    count = n;
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  ~UnionFind() {
    delete[] parent;
    delete[] rank;
  }
  int getCount() { return count; }
  int mfind(int p) {
    while (p != parent[p]) // 隔代压缩
    {
      parent[p] = parent[parent[p]];
      p = parent[p];
    }
    return p;
  }
  bool isConnected(int p, int q) { return mfind(p) == mfind(q); }
  void munion(int p, int q) {
    int pRoot = mfind(p);
    int qRoot = mfind(q);
    if (pRoot == qRoot)
      return;
    if (rank[pRoot] > rank[qRoot])
      parent[qRoot] = pRoot;
    else if (rank[pRoot] < rank[qRoot])
      parent[pRoot] = qRoot;
    else {
      parent[qRoot] = pRoot;
      rank[pRoot]++;
    }
    count--;
  }
};

int findCircleNum(vector<vector<int>> &M) {
  int len = M.size();
  UnionFind uf(len);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (M[i][j] == 1)
        uf.munion(i, j);
    }
  }
  return uf.getCount();
}

int main() {
  vector<vector<int>> vi{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  assert(2 == findCircleNum(vi)); // 0,1互为朋友在一个朋友圈.2自己在一个朋友圈
  vector<vector<int>> vi1{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
  assert(1 == findCircleNum(vi1)); // 0,1,2在一个朋友圈
}


