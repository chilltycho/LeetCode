#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return intersect(nums2, nums1);
    unordered_map<int, int> m; //哈希表，前一个为值，后一个出现次数
    for (auto n : nums1)
    {
        ++m[n]; //对元素多的建立哈希表
    }
    int k = 0;
    for (auto n : nums2) //遍历nums2
    {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0) //若nums1中存在nums2中的值，哈希表中值相应次数减一
            nums1[k++] = n;                    //nums1在建立哈希表后没用了，这里直接存储结果
    }
    return vector(begin(nums1), begin(nums1) + k);
}

vector<int> intersect_1(vector<int> &nums1, vector<int> &nums2)
{
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    int i = 0, j = 0, k = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else
        {
            nums1[k++] = nums1[i++];
            j++;
        }
    }
    return vector<int>(begin(nums1),begin(nums1)+k);
}

int main()
{
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    auto re = intersect(nums1, nums2);
    for (const auto c : re)
        cout << c << ' ';
}