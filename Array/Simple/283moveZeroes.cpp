/*将所有0移动到数组末尾，同时保持非零元素相对顺序*/
#include <vector>
#include <iostream>
using namespace std;
void bubleup(vector<int> &nums, int r)
{
    while (nums[r] != 0 && r < nums.size())
    {
        swap(nums[r - 1], nums[r]);
        r++;
    }
}
void moveZeroes(vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    int l = nums.size() - 2;
    int r = nums.size() - 1;
    while (l >= 0)
    {
        if (nums[l] == 0)
        {
            bubleup(nums, r);
            r = l;
            --l;
        }
        else
        {
            l--;
            r--;
        }
    }
}
void moveZeroes_1(vector<int> &nums)
{
    int lastNonZerosFoundAt = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != 0)
            nums[lastNonZerosFoundAt++] = nums[i];
    for (int i = lastNonZerosFoundAt; i < nums.size(); i++)
        nums[i] = 0;
}

void moveZeroes_2(vector<int> &nums)
{
    //[0,slow]为非零,[slow,cur]为0
    for (int slow = 0, cur = 0; cur < nums.size(); cur++)
        if (nums[cur] != 0)
            swap(nums[slow++], nums[cur]);
}

int main()
{
    vector<int> vi{0, 1, 0, 3, 12};
    moveZeroes(vi);
    for (auto c : vi)
        cout << c << ' ';
    cout << endl;
}