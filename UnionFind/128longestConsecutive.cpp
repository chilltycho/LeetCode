/*给定未排序的整数数组,找出最长连续序列的长度.应该相隔为1*/
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int longestConsecutive_bru(vector<int> &nums)
{
    int len = nums.size();
    if (len < 2)
        return len;
    sort(nums.begin(), nums.end());
    int longestLen = 1;
    int res = 1;
    int pre = nums[0];
    for (int i = 1; i < len; i++)
    {
        if (nums[i] == nums[i - 1])
            continue; //重复元素不算
        else if (nums[i] == pre + 1)
        {
            longestLen++;
            res = max(res, longestLen);
        }
        else
            longestLen = 1;
        pre = nums[i];
    }
    return res;
}

int longestConsecutive_set(vector<int> &nums)
{
    int len = nums.size();
    if (len < 2)
        return len;
    unordered_set<int> si;
    for (auto num : nums)
        si.insert(num);
    int res = 0;
    for (auto num : si)
    {
        if(si.find(num-1)==si.end())
        {
            int currentNum=num;
            int longestLen=1;
            while(si.find(currentNum+1)!=si.end())
            {
                currentNum++;
                longestLen++;
            }
            res=max(longestLen,res);
        }
    }
    return res;
}

class UnionFind
{
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size; //以当前节点为根的子树的节点总数
public:
    UnionFind(vector<int> &nums)
    {
        int len = nums.size();
        for (const auto &num : nums)
        {
            parent.insert({num, num});
            size.insert({num, 1});
        }
    }
    int munion(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return 0;
        int sizeX = size[rootX];
        int sizeY = size[rootY];
        int sum = sizeX + sizeY;
        if (sizeX < sizeY)
        {
            parent[rootX] = rootY;
            size[rootY] = sum;
        }
        else
        {
            parent[rootY] = rootX;
            size[rootX] = sum;
        }
        return sum;
    }
    int find(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool contains(int x)
    {
        if (parent.find(x) != parent.end())
            return true;
        else
            return false;
    }
};

int longestConsecutive_UF(vector<int> &nums)
{
    int len = nums.size();
    if (len < 2)
        return len;
    UnionFind unionFind(nums);
    int res = 1;
    for (const auto &num : nums)
    {
        if (unionFind.contains(num - 1))
            res = max(res, unionFind.munion(num, num - 1));
        if (unionFind.contains(num + 1))
            res = max(res, unionFind.munion(num, num + 1));
    }
    return res;
}

int main()
{
    vector<int> vi{100, 4, 200, 1, 3, 2}; //1,2,3,4
    cout << longestConsecutive_UF(vi);
}