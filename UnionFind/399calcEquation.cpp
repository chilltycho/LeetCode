/*给出方程式A/B=k,根据已知方程式求解问题,并返回结果,若结果不存在,返回-1*/
#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;
class UnionFind
{
public:
    int *parent;
    double *weight; //将父节点作为分母时的商
public:
    UnionFind(int n)
    {
        parent = new int[n];
        weight = new double[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            weight[i] = 1.0;
        }
    }
    ~UnionFind()
    {
        delete[] parent;
        delete[] weight;
    }
    void munion(int x, int y, double value)
    {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
        weight[rootX] = weight[y] * value / weight[x];
    }
    int find(int x)
    {
#if 1
        if (x != parent[x])
        {
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
        }
        return parent[x];
#endif
    }
    double isConnected(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return weight[x] / weight[y];
        }
        else
            return -1.0;
    }
};

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int equationSize = equations.size();
    unordered_map<string, int> hashMap;
    UnionFind unionFind(2 * equationSize);
    int id = 0;
    for (int i = 0; i < equationSize; i++)
    {
        auto equation = equations[i];
        auto var1 = equation[0];
        auto var2 = equation[1];
        if (hashMap.find(var1) == hashMap.end())
        {
            hashMap[var1] = id;
            id++;
        }
        if (hashMap.find(var2) == hashMap.end())
        {
            hashMap[var2] = id;
            id++;
        }
        unionFind.munion(hashMap[var1], hashMap[var2], values[i]);
    }

    int queriesSize = queries.size();
    vector<double> res(queriesSize, 0);
    for (int i = 0; i < queriesSize; i++)
    {
        auto var1 = queries[i][0];
        auto var2 = queries[i][1];
        if (hashMap.find(var1) != hashMap.end() && hashMap.find(var2) != hashMap.end())
            res[i] = unionFind.isConnected(hashMap[var1], hashMap[var2]);
        else
            res[i] = -1.0;
    }
    return res;
}

int main()
{
    // a/b=2 b/c=3 则a/c=6 b/a=0.5 a/e=-1 a/a=1 x/x=-1
    vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
    vector<double> values{2.0, 3.0};
    vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> res{6.0, 0.5, -1.0, 1.0, -1.0};
    assert(res == calcEquation(equations, values, queries));
}