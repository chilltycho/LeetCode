#include<iostream>
#include<vector>
using namespace std;
//f(k)=max(f(k-2)+Ak,f(k-1))
int rob(vector<int>& nums)
{
    int preMax=0,currMax=0;
    for(int x:nums)
    {
        int temp=currMax;
        currMax=max(preMax+x,currMax);
        preMax=temp;
    }
    return currMax;
}
int main()
{
    vector<int> vi{2,7,9,3,1};
    cout<<rob(vi);
}