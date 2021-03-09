/*加油站，第i个加油站可加油gas[i],从第i个前往i+1个需耗油cost[i]。
从任一个加油站出发，求是否能环一圈，若不能，返回-1,答案唯一
*/
#include <vector>
#include <cassert>
using namespace std;
// 暴力法
int can_vio(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    // 从每个点出发
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int remain = gas[i];
        // 当前剩余油可到达下一点
        while (remain - cost[j] >= 0)
        {
            remain = remain - cost[j] + gas[(j + 1) % n];
            j = (j + 1) % n;
            if (j == i)
                return i; // 回到i
        }
    }
    return -1;
}
// 优化，记录每个点能到达最远距离
int can_1(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    vector<int> farIndex(n, -1);      // 能到达最远距离
    vector<int> farIndexRemain(n, 0); // 到达最远距离剩余汽油
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int remain = gas[i];
        while (remain - cost[j] >= 0)
        {
            remain = remain - cost[j];
            j = (j + 1) % n;
            if (farIndex[j] != -1)
            { //直接跳到j
                remain = remain + farIndexRemain[j];
                j = farIndex[j];
            }
            else
            {
                remain = remain + gas[j];
            }
            if (i == j)
                return i;
        }
        farIndex[i] = j;
        farIndexRemain[i] = remain;
    }
    return -1;
}

// 折线图，保证最低点在水平线即可
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int len = gas.size();
    int spare = 0;              //当前剩余油量
    int minSpare = __INT_MAX__; //剩余油量最小值
    int minIndex = 0;           //剩余油量最小时索引
    for (int i = 0; i < len; i++)
    {
        spare += gas[i] - cost[i];
        if (spare < minSpare)
        {
            minSpare = spare;
            minIndex = i;
        }
    }
    return spare < 0 ? -1 : (minIndex + 1) % len;
}

int main()
{
    vector<int> g{1, 2, 3, 4, 5}, c{3, 4, 5, 1, 2};
    assert(3 == canCompleteCircuit(g, c));
}