/*气球的最大数量：给定一个字符串text，用text中字母来拼凑尽可能多的"balloon"，每个字母只能使用1次
输入：nlaebolko
输出：1*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int maxNumberOfBallons(string text)
{
    string ballon="balloon";
    unordered_map<char,int> um={{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
    for(auto c:text)
    {
        if(c=='b'||c=='a'||c=='l'||c=='o'||c=='n')
            um[c]++;
    }
    um['l']/=2;
    um['o']/=2;
    int res=INT_MAX;
    for(auto c:um)
    {
        res=min(c.second,res);
    }
    return res;
}

int main()
{
    string t1="leetcode";
    cout<<maxNumberOfBallons(t1);
}