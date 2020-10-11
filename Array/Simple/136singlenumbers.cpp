#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//只有一个数字出现一次，其他出现两次
int single(int a[], int n)
{ //位操作，一个数本身求异或为1，对异己的为0，
    int temp = 0;
    for (int i = 0; i < n; i++)
        temp = temp ^ a[i];
    return temp;
}

int single_map(vector<int>& nums)
{
    unordered_map<int,int> um;
    for(const auto &c:nums)
        um[c]++;
    for(auto c:um)
    {
        if(c.second==1)
            return c.first;
    }
    return -1;
}
int main()
{
    int a[]{2, 0, 2, 1, 1};
    cout << single(a, 3) << endl;
    int b[]{0};
    cout << single(b, 1) << endl;
}