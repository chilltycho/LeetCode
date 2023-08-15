//加权实现,find(),connected(),和union()为logN
class WeightedQuickUnionUF {
private:
  int *id;
  int *sz; //权值,当前节点下子结点个数.无法保证树深度最小
  int count;

public:
  WeightedQuickUnionUF(int N) {
    count = N;
    id = new int[N];
    sz = new int[N];
    for (int i = 0; i < N; i++) {
      id[i] = i;
      sz[i] = 1; //初始时节点指向自己,为1
    }
  }
  ~WeightedQuickUnionUF() {
    delete[] id;
    delete[] sz;
  }
  int find(int p) {
    while (p != id[p])
      p = id[p];
    return p;
  }
  void munion(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot)
      return;
    if (sz[pRoot] < sz[qRoot]) // p根权值小于q,应将pRoot挂载到qRoot上
    {
      id[pRoot] = qRoot;
      sz[qRoot] += sz[pRoot];
    } else {
      id[qRoot] = pRoot;
      sz[pRoot] += sz[qRoot];
    }
    count--;
  }
};
