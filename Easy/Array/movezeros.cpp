#include <vector>
#include <iostream>
using namespace std;
//将数组中所有0移动到数组末尾，非零元素相对顺序不变。
void moveZeroes(vector<int> &nums)
{
    int i = 0, j = 0;
    while (j < nums.size() && i <= j)
    {

        if (nums[i] == 0)
        {
            while (nums[j] == 0)
            {
                if (j == nums.size() - 1)
                    return;
                else
                    j++;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
}

void moveZeros_1(vector<int> &nums)
{
    int n = nums.size();
    int numZeroes = 0;
    for (int i = 0; i < n; i++)
        numZeroes += (nums[i] == 0);

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (nums[i] != 0)
            ans.push_back(nums[i]);

    while (numZeroes--)
        ans.push_back(0);

    for (int i = 0; i < n; i++)
        nums[i] = ans[i];
}

void moveZeroes_2(vector<int> &nums)
{
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++)////先记录0的个数，将0覆盖为最近的非零元素
        if (nums[i] != 0)
            nums[lastNonZeroFoundAt++] = nums[i];

    for (int i = lastNonZeroFoundAt; i < nums.size(); i++)//将最后几位覆盖为0，对全为0时，该方法冗余
        nums[i] = 0;
}

void moveZeros_3(vector<int> &nums)
{
    for(int lastNonZeroFoundAt=0,cur=0;cur<nums.size();cur++)//慢指针lastnon之前所有元素非0，当前指针与慢速指针间所有元素为0
        if(nums[cur]!=0)
            swap(nums[lastNonZeroFoundAt++],nums[cur]);
}

int main()
{
    vector<int> vi{0, 1, 0, 3, 12};
    moveZeroes(vi);
    for (auto c : vi)
        cout << c << ' ';
}