#include <vector>
using namespace std;
vector<int> temp;
vector<vector<int>> res;
vector<vector<int>> FindContinuousSequence(int sum)
{
    int len = sum / 2 + 1;
    vector<vector<int>> res;
    vector<int> path;
    int windowsum = 0;
    for (int l = 1, r = 1; r <= len; ++r)
    {
        windowsum+=r;
        if(windowsum>sum)
        {
            windowsum-=l;
            ++l;
        }
        if(windowsum==sum)
        {
            vector<int> tmp;
            for(int i=l;i<=r;++i)
                tmp.push_back(i);
            res.push_back(tmp);
            windowsum-=l;
            ++l;
        }
    }
    return res;
}