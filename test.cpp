#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int maxLength(vector<int> &arr)
{
    // write code here
    if (arr.empty())
        return 0;
    unordered_map<int, int> um;
    int res = 0;
    for (auto c : arr)
    {
        if (um.count(c) == 0)
        {
            um[c]++;
            res++;
        }
    }
    return res;
}

int main()
{
    vector<int> vi{2, 2, 3, 4, 3};
    cout << maxLength(vi) << endl;
}