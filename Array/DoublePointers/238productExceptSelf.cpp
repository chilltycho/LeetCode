// 求除自身外其余元素乘积的数组。
#include <vector>
using namespace std;
/*[1,2,3,4]
初始化res=[1,1,1,1], l=1, r=1
i=0,j=3, res=[1,1,1,1],l=1,r=4
i=1,j=2, res=[1,1,4,1],l=2,r=12
i=2,j=1, res=[1,12,8,1], l=6, r=24
i=3,j=0, res=[24,12,8,6] 输出res
*/

// 除自身的乘积等于左边乘积和右边乘积。
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res(nums.size(), 1);
    int l = 1, r = 1;
    for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j)
    {
        res[i] *= l;
        res[j] *= r;
        l *= nums[i];
        r *= nums[j];
    }
    return res;
}