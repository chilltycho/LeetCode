#include <iostream>
using namespace std;
class UF
{
private:
    int *id;   //分量id
    int count; //分量个数
    int sizeId;

public:
    UF(int N)
    {
        sizeId = N;
        count = N;
        id = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;
    }
    ~UF()
    {
        delete[] id;
    }
    int getCount()
    {
        return count;
    }
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
    int find(int p);
    void munion(int p, int q);
    int find1(int p);
    void munion1(int p, int q);
};
//quick_find,对每对输入munion()需要扫描整个id数组
int UF::find(int p)
{
    return id[p];
}

void UF::munion(int p, int q)
{
    int pId = find(p);
    int qId = find(q);
    if (pId == qId)
        return;
    for (int i = 0; i < sizeId; i++)
        if (id[i] == pId)
            id[i] = qId;
    count--;
}

//quick-union,与输入有关
int UF::find1(int p)
{
    while (p != id[p])
        p = id[p]; //找到根节点
    return p;
}
void UF::munion1(int p, int q)
{
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot)
        return;
    id[pRoot] = qRoot;
    count--;
}
