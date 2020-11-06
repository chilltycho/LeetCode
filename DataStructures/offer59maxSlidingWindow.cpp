#include <deque>
#include <iostream>
#include <vector>
using namespace std;
//单调递减队列，最大元素总在头部
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.empty() || k == 0)
        return vector<int>{};
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();
        dq.push_back(nums[i]);
    }
    vector<int> res(nums.size() - k + 1);
    res[0] = dq.front();
    for (int i = k; i < nums.size(); i++)
    {
        //滑动窗口已经略过队列中头部元素
        if (dq.front() == nums[i - k])
            dq.pop_front();
        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();
        dq.push_back(nums[i]);
        res[i - k + 1] = dq.front();
    }
    return res;
}

int main()
{
    vector<int> nums{1, 3, -1, -3, 5, 4, 6, 7};
    auto res = maxSlidingWindow(nums, 3);
    for (auto &c : res)
        cout << c << ' ';
}