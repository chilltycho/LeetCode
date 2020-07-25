/*对比78题，包含重复整数数组
输入：[1,2,2] 输出：[2],[1],[1,2,2],[2,2],[1,2],[]]*/
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> res;
void dfs(vector<int> &nums, int start, vector<int> &track)
{
    res.push_back(track);
    for (int i = start; i < nums.size(); i++)
    {
        if (!(i > start && nums[i] == nums[i - 1]))
        {
            track.push_back(nums[i]);
            dfs(nums, i + 1, track);
            track.pop_back();
        }
    }
}

vector<vector<int>> subsets_1(vector<int> &nums)
{
    vector<int> track;
    sort(nums.begin(),nums.end());
    dfs(nums, 0, track);
    return res;
}

int main()
{
    vector<int> nums{1,2,2};
    auto res=subsets_1(nums);
    for(auto c:res)
    {
        for(auto cc:c)
            cout<<cc<<' ';
        cout<<endl;
    }
}