#include<algorithm>
#include <vector>
#include<iostream>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1;i<intervals.size();++i)
    {
        int newl=intervals[i][0];
        int oldr=res.back()[1];
        if(newl<=oldr)
            res.back()[1]=max(intervals[i][1],oldr);
        else
            res.push_back(intervals[i]);
    }
    return res;
}
int main()
{
    vector<vector<int>> vi{{1,3},{2,6},{8,10},{15,18}};
    auto res = merge(vi);//{{1,6},{8,10},{15,18}};
    for(auto i:res)
    {
        for(auto ii:i)
            cout<<ii<<' ';
        cout<<endl;
    }
}