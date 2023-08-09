/*给定山脉数组，返回等于target的最小下标index值，若不存在返回-1*/
#include <iostream>
#include <vector>
using namespace std;

// int findMountainTop(int left, int right, vector<int> &nums)
// {
//     while (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < nums[mid + 1]) //中间偏左一定有右边元素，不用考虑越界
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     return left;
// }

// int findFromSortedArr(int left, int right, int target, vector<int> &nums)
// {
//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] == target)
//             return mid;
//         if (nums[mid] < target)
//             left = mid + 1;
//         else
//             right = mid - 1;
//     }
//     return -1;
// }

// int findFromInversedArr(int left, int right, int target, vector<int> &nums)
// {
//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] == target)
//             return mid;
//         if (nums[mid] < target)
//             right = mid - 1;
//         else
//             left = mid + 1;
//     }
//     return -1;
// }

// //先找到最大值，在向左找，若找不到，向右找。
// int findInMountainArray(int target, vector<int> &nums)
// {
//     int len = nums.size(); //应大于3
//     int mountainTop = findMountainTop(0, len - 1, nums);
//     int res = findFromSortedArr(0, mountainTop, target, nums); //返回最小下标，先向左找，升序
//     if (res != -1)
//         return res;
//     return findFromInversedArr(mountainTop + 1, len - 1, target, nums); //降序
// }
int findTop(vector<int> &mountainArr){
        int l=0,r=mountainArr.size();
        while(l<r){
            int m=l+(r-l)/2;
            if(m+1<mountainArr.size()&&mountainArr.at(m)<mountainArr.at(m+1)){
                l=m+1;
            }else {
                r=m;
            }
        }
        return l;
    }

    int bi_search(int target, int top_index,vector<int> &mountainArr){
        int l=0,r=top_index+1;
        while(l<r){
            int m=l+(r-l)/2;
            if(mountainArr.at(m)<target){
                l=m+1;
            }else{
                r=m;
            }
        }
        if(l<=top_index&&mountainArr.at(l)==target){
            return l;
        }
        return -1;
    }

    int bi_search_reverse(int target, int top_index,vector<int> &mountainArr){
        int l=top_index,r=mountainArr.size();
        while(l<r){
            int m=l+(r-l)/2;
            if(mountainArr.at(m)>target){
                l=m+1;
            }else{
                r=m;
            }
        }
        if(l<mountainArr.size()&&mountainArr.at(l)==target){
            return l;
        }
        return -1;
    }

    int findInMountainArray(int target, vector<int> &mountainArr) {
        int top_index=findTop(mountainArr);
        cout<<top_index<<endl;
        int search_l=bi_search(target, top_index, mountainArr);
        if(search_l!=-1){
            return search_l;
        }
        return bi_search_reverse(target, top_index, mountainArr);
    }
int main()
{
    vector<int> nums{1,3,5,2,0};
    cout<<findInMountainArray(2,nums);
}