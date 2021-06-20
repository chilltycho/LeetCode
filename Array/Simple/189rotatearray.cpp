/*给定数组,将数组中元素右移k个位置,k为非负数*/
#include <iostream>
#include <vector>
using namespace std;

void viorotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    for (int i = 0; i < k; i++)
    {
        int temp = nums[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}

void rotate_1(vector<int> &nums, int k)
{
    //k = k % n;
    int n = nums.size();
    int count = 0; //每个元素移动一次，等于数组长度时，换位完成
    for (int start = 0; count < n; start++)
    {
        int current = start;
        int prev = nums[start];
        do
        {
            int next = (current + k) % n;

            int temp = nums[next];
            nums[next] = prev;
            prev = temp;

            current = next;
            count++;
        } while (start != current);
    }
}

void reverse(vector<int> &nums, int i, int j)
{
    while(i<j)
    {
        swap(nums[i++],nums[j--]);
    }
}

void rotate_2(vector<int> &nums, int n, int k)
{
    k = k % n;
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6};
    rotate_1(nums, 2);
    for (int c : nums)
        cout << c << ' ';
    cout << endl;
}