/*在下标0处，每步最多可往前跳k步，不能跳出数组边界，目标是到达
数组最后一个位置(下标为n-1)，得分是经过所有数字之和，返回最大得分*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
/* 用f[i]表示从下标0到下标i的最大得分。f[i]=max(f[j])+nums[i] 其中i-k<=j<i
最大化f[j],可用优先队列维护所有(f[j],j)
*/
int maxResult(vector<int> &nums, int k)
{
    int n = nums.size();
    //优先队列中二元组(f[j],j)
    priority_queue<pair<int, int>> q;
    q.emplace(nums[0], 0);
    int ans = nums[0];

    for (int i = 1; i < n; i++)
    {
        //堆顶j不满足限制
        while (i - q.top().second > k)
            q.pop();
        ans = q.top().first + nums[i];
        q.emplace(ans, i);
    }
    return ans;
}

int main()
{
    
}