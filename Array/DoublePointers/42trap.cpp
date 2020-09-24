#include <vector>
#include <cassert>
using namespace std;
int getMax(vector<int> &height)
{
    int hm = 0;
    for (int i = 0; i < height.size(); i++)
        hm = max(hm, height[i]);
    return hm;
}
//按行求，求第i层的水
int trap_1(vector<int> &height)
{
    int sum = 0;
    int maxh = getMax(height);
    for (int i = 1; i <= maxh; i++)
    {
        bool isStart = false;
        int temp = 0;
        for (int j = 0; j < height.size(); j++)
        {
            if (isStart && height[j] < i)
                temp++;
            if (height[j] >= i)
            {
                sum += temp;
                temp = 0;
                isStart = true;
            }
        }
    }
    return sum;
}

//按列求
int trap_2(vector<int> &height)
{
    int sum = 0;
    //两端列不会有水
    for (int i = 1; i < height.size() - 1; i++)
    {
        int max_left = 0; //左边最高
        for (int j = i - 1; j >= 0; j--)
            max_left = max(height[j], max_left);
        int max_right = 0; //右边最高
        for (int j = i + 1; j < height.size(); j++)
            max_right = max(height[j], max_right);
        int min_lr = min(max_left, max_right);
        if (min_lr > height[i])
            sum += (min_lr - height[i]);
    }
    return sum;
}

//提前保存每列左边最高，右边最高。动态规划
int trap_3(vector<int> &height)
{
    int len = height.size();
    int sum = 0;
    vector<int> max_left(len, 0);
    vector<int> max_right(len, 0);
    for (int i = 1; i < len; i++)
        max_left[i] = max(max_left[i - 1], height[i - 1]);
    for (int i = len - 2; i >= 0; i--)
        max_right[i] = max(max_right[i + 1], height[i + 1]);
    for (int i = 1; i < len - 1; i++)
    {
        int min_lr = min(max_left[i], max_right[i]);
        if (min_lr > height[i])
            sum += (min_lr - height[i]);
    }
    return sum;
}

//法3中数组元素只用了一次
int trap_4(vector<int> &height)
{
    int len = height.size();
    int sum = 0, max_left = 0, max_right = 0;
    int left = 1;
    int right = len - 2; //右指针
    for (int i = 1; i < len - 1; i++)
    {
        if (height[left - 1] < height[right + 1]) //较矮的在左边
        {
            max_left = max(max_left, height[left - 1]);
            int min_lr = max_left;
            if (min_lr > height[left])
                sum += (min_lr - height[left]);
            left++;
        }
        else
        {
            max_right = max(max_right, height[right + 1]);
            int min_lr = max_right;
            if (min_lr > height[right])
                sum += (min_lr - height[right]);
            right--;
        }
    }
    return sum;
}

int main()
{
    vector<int> vi{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(6 == trap_4(vi));
}