#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ret;
    vector<int> line(numRows, 1);
    for (int i = 0; i < numRows; i++)
    {
        int t = 1;
        for (int j = 1; j < i; j++)
        {
            int temp = line[j];
            line[j] = t + line[j];
            t = temp;
        }
        ret.push_back(vector<int>(line.begin(), line.begin() + i + 1));
    }
    return ret;
}
//动态规划：dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
vector<vector<int>> generate_1(int numRows)
{
    vector<vector<int>> res;
    for (int i = 1; i <= numRows; i++)
    {
        vector<int> val(i);
        val[i - 1] = 1;
        val[0] = 1;
        if (i <= 2)
        {
            res.push_back(val);
            continue;
        }
        for (int j = 1; j < i - 1; j++)
        {
            val[j] = res[i - 2][j - 1] + res[i - 2][j];
        }
        res.push_back(val);
    }
    return res;
}

int main()
{
    auto vii = generate_1(5);
    for (auto vi : vii)
    {
        for (auto c : vi)
            cout << c << ' ';
        cout << endl;
    }
}