/*将所有0移动到数组末尾，同时保持非零元素相对顺序*/
#include <vector>
#include <iostream>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int index = -1; //[0,index]为非零 [index+1,nums.size())为0
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            swap(nums[++index], nums[i]);
    }
}

int main()
{
    vector<int> vi{0, 1, 0, 3, 12};
    moveZeroes(vi);
    for (auto c : vi)
        cout << c << ' ';
    cout << endl;
}