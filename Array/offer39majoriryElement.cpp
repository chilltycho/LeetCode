//找出数组中出现次数超过一半的数字
#include <vector>
#include <cassert>
using namespace std;
//超过总数0.5的兵力，全部消耗后剩的是最多的。
int majorityElement(vector<int> &nums)
{
    int moleVote = 0, res = 0;
    for (const auto &c : nums)
    {
        if (moleVote == 0)
            res = c;
        moleVote += res == c ? 1 : -1;
    }
    return res;
}

int main()
{
    
}