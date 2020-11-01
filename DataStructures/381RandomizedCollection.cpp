/*设计支持在平均时间复杂度O(1)下，执行以下操作的数据结构
1.插入元素 2.当val存在时，删除val 3.随机获取一个元素*/
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*O(1)时间内能随机获取一个元素，将元素存在数组中，随机获取时，随机生成索引
删除时，将被删元素与数组最后一个元素交换，然后O(1)时间内删除元素。
需要额外维护数值在数组中每次出现下标，对val，记下标为Sidx*/
class RandomizedCollection
{
private:
    unordered_map<int,unordered_set<int>> idx;
    vector<int> nums;
public:
    bool insert(int val)
    {
        nums.push_back(val);//数组加入
        idx[val].insert(nums.size()-1);//加入map，并记住索引
        return idx[val].size()==1;
    }
    bool remove(int val)
    {
        if(idx.find(val)==idx.end())//判断是否存在
            return false;
        int i=*(idx[val].begin());//第一次出现位置
        nums[i]=nums.back();//交换到数组尾
        idx[val].erase(i);//删除val第一次出现下标
        idx[nums[i]].erase(nums.size()-1);//删除nums[i]最后一次下标
        if(i<nums.size()-1)
            idx[nums[i]].insert(i);
        if(idx[val].size()==0)
            idx.erase(val);
        nums.pop_back();
        return true;
    }
    int getRandom()
    {
        return nums[rand()%nums.size()];
    }
};

