#include<vector>
using namespace std;
vector<int> temp;
vector<vector<int>> res;
vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
    vector<int> path;
    int windowsum = 0;
    for (int r = 1; r <= (sum + 1) / 2; r++)
    {
        windowsum += r;
        path.push_back(r);
        while (windowsum >= sum)
        {
            if (windowsum == sum)
            {
                if (path.size() > 1)
                    res.push_back(path);
            }
            windowsum -= *(path.begin());
            path.erase(path.begin());
        }
    }
    return res;
}