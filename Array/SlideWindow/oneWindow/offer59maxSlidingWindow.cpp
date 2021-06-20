// k大窗口中最大值
#include <deque>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
最大堆, O(nlogn)
*/
vector<int> maxSlidingWindow_1(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i)
        q.emplace(nums[i], i);
    vector<int> res{q.top().first};
    for (int i = k; i < n; ++i)
    {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k)
            q.pop();
        res.push_back(q.top().first);
    }
    return res;
}

/**
 * deque内仅包含窗口内的元素：每轮窗口滑动移除了元素nums[i-1]，需将deque内对应的元素一起删除
 * deque内元素非严格递减：每轮窗口滑动添加了元素nums[j+1]，需将deque内所有<nums[j+1]元素删除
*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.empty() || k == 0)
        return vector<int>{};
    deque<int> dq;
    vector<int> res(nums.size() - k + 1, 0);
    for (int j = 0, i = 1 - k; j < nums.size(); i++, j++)
    {
        // 删除dq中对应nums[i-1]
        if (i > 0 && dq.front() == nums[i - 1])
            dq.pop_front();
        // 保持dq递减
        while (!dq.empty() && dq.back() < nums[j])
            dq.pop_back();
        dq.push_back(nums[j]);
        // 记录窗口最大值
        if (i >= 0)
            res[i] = dq.front();
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