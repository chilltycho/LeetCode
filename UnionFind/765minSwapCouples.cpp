//计算最少交换座位次数,使相隔1的数并肩
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
class UnionFind
{
private:
    int *parent;
    int count;

public:
    UnionFind(int n)
    {
        count = n;
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    ~UnionFind()
    {
        delete[] parent;
    }
    int find(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void munion(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        parent[rootX] = rootY;
        count--;
    }
    int getCount()
    {
        return count;
    }
};
//每对编号/2后{0,0},{1,1},每对沙发上编号union,若本来编号相同,则同一类,若不相同,分量+1
int minSwapsCouples(vector<int> &row)
{
    int len = row.size();
    int N = len / 2;
    UnionFind uf(N);
    for (int i = 0; i < N; i++)
        uf.munion(row[2 * i] / 2, row[2 * i + 1] / 2);
    return N - uf.getCount();
}

int main()
{
    vector<int> row{0, 2, 1, 3}; //使{0,1},{2,3}相邻,交换1,2即可
    assert(1 == minSwapsCouples(row));
    vector<int> row1{3, 2, 0, 1}; //无需交换
    assert(0 == minSwapsCouples(row1));
}