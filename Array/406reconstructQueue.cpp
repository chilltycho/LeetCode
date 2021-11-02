//每个人由整数对(h,k)表示，h为身高，k为排在这个人前面身高大于或等于h的人数。
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
//先排最高的,前面人数较少的
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), cmp);
    list<vector<int>> que;
    for (int i = 0; i < people.size(); i++)
    {
        int position = people[i][1];
        auto ite = que.begin();
        while (position--)
            ite++;
        que.insert(ite, people[i]);
    }
    return vector<vector<int>>(que.begin(), que.end());
}

int main()
{
    //结果[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    vector<vector<int>> vi{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
} 