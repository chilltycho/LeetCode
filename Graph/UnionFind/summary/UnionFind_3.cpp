class UnionFind {
private:
  int *parent;
  int *rank; //以下标为i的元素为根节点的树的深度
  int count;
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
    delete[] rank;
    delete[] parent;
  }
  int find(int p) {
    while (p != parent[p])
      p = parent[p];
    return p;
  }
  void munion(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
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

