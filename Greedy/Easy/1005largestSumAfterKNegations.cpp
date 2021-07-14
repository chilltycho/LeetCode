#include <vector>
#include <queue>
using namespace std;
// 每次将最小的取相反数
int largestSumAfterKNegations(vector<int> &nums, int k)
{
    vector<int> number(201, 0);
    for (auto c : nums)
        ++number[c + 100]; // 计数排序
    int i = 0;
    while (k > 0)
    {
        while (number[i] == 0) // 找到最小的数
            ++i;
        --number[i];
        ++number[200 - i];
        if (i > 100) // 产生了负数
            i = 200 - i;
        --k;
    }
    int res = 0;
    for (int j = i; j < number.size(); ++j)
        res += (j - 100) * number[j];
    return res;
}

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto c : nums)
        pq.push(c);
    while (k)
    {
        auto c = pq.top();
        pq.pop();
        pq.push(-c);
        --k;
    }
    int res = 0;
    while (pq.size())
    {
        res += pq.top();
        pq.pop();
    }
    return res;
}