/*隔代压缩,虽然压缩不彻底,但多压缩几次就能达到完全压缩的效果
不使用递归,不占用递归栈空间
在find时,让树高度降低*/
int find(int p) {
  while (p != parent[p]) {
    //隔代压缩,根节点父节点还是自己,不会出现空指针
    parent[p] = parent[parent[p]];
    p = parent[p];
  }
  return p;
}

int find_1(int p) {
  if (p != parent[p]) { 
    //只要不是根节点,就把父节点指向父节点的父节点
    parent[p] = find(parent[p]);
  }
  return parent[p];
}
