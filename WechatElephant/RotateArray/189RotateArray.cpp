#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& nums,int begin,int end)
{
    int temp;
    for(int i=begin,j=end-1;i<j;i++,j--)
    {
        temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}

void rotate(vector<int>& nums,int k)
{
    int N=nums.size();
    k%=N;
    reverse(nums,0,N);
    reverse(nums,0,k);
    reverse(nums,k,N);

}

int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8};
    rotate(vi,3);
    for(auto c:vi)
        cout<<c<<' ';
}