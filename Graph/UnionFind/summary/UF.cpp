const int MAXN = 1000;
int fa[MAXN]; // 保存每个元素父节点
int rank[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i; // 初始时父节点为自身
}

// 查父节点
int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

// 并，将前者父节点设为后者父节点，或反之
void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

// 路径压缩， 查询过程中，将沿途每个节点的父节点设为根节点。
int find(int x)
{
    if (x == fa[x])
        return x;
    else
    {
        fa[x] = find(fa[x]); //父节点设为根节点
        return fa[x];        // 返回父节点
    }
}

// 按秩合并, 将简单的树往复杂树上靠
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}

void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++; //深度相同根节点不同，新根节点深度+1
}
