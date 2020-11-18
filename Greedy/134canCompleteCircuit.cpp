/*加油站，第i个加油站可加油gas[i],从第i个前往i+1个需耗油cost[i]。
从任一个加油站出发，求是否能环一圈，若不能，返回-1,答案唯一
*/
#include <vector>
#include <cassert>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int len = gas.size();
    int spare = 0;//当前剩余油量
    int minSpare = __INT_MAX__;//剩余油量最小值
    int minIndex = 0;//剩余油量最小时索引
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