#include<vector>
using namespace std;
vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    vector<int> res;
    if (array.empty())
        return res;
    int l = 0, r = array.size() - 1;
    while (l < r)
    {
        if (array[l] + array[r] < sum)
            l++;
        else if (array[l] + array[r] == sum)
        {
            res.push_back(array[l]);
            res.push_back(array[r]);
            return res;
        }
        else
            r--;
    }
    return res;
}