#include <vector>
#include <string>
#include <cassert>
using namespace std;

class UnionFind
{
private:
    int *parent;

public:
    ~UnionFind()
    {
        delete[] parent;
    }
    UnionFind(int N)
    {
        parent = new int[N];
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }
    bool isConnected(int p, int q)
    {
        return mfind(p) == mfind(q);
    }
    void munion(int p, int q)
    {
        int pId = mfind(p);
        int qId = mfind(q);
        parent[pId] = qId;
    }
    int mfind(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

bool equationsPossible(vector<string> equations)
{
    UnionFind unionFind(26);
    for (auto e : equations)//第一次遍历,将等式两边顶点合并
    {
        if (e[1] == '=')
        {
            int index1 = e[0] - 'a';
            int index2 = e[3] - 'a';
            unionFind.munion(index1, index2);
        }
    }
    for (auto e : equations)//第二次遍历,检查不等式两顶点是否在一个连通分量中
    {
        if (e[1] == '!')
        {
            int index1 = e[0] - 'a';
            int index2 = e[3] - 'a';
            if (unionFind.isConnected(index1, index2))
                return false;
        }
    }
    return true;
}

int main()
{
    vector<string> vi{"a==b", "b!=a"};
    assert(!equationsPossible(vi));
    vector<string> vi1{"b==a", "a==b"};
    assert(equationsPossible(vi1));
    vector<string> vi2{"a==b", "b==c", "a==c"};
    assert(equationsPossible(vi2));
    vector<string> vi3{"a==b", "b!=c", "c==a"};
    assert(!equationsPossible(vi3));
    vector<string> vi4{"c==c", "b==d", "x!=z"};
    assert(equationsPossible(vi4));
}