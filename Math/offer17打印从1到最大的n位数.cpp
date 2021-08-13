#include <queue>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> printNumbers(int n)
{
    if (n == 0)
        return vector<ll>{};
    vector<ll> res(pow(10, n) - 1);
    queue<string> q;
    for (int i = 1; i <= 9; ++i)
        q.push(to_string(i));
    int index = 0, length = 1;
    while (q.size())
    {
        int siz = q.size();
        for (int i = 0; i < siz; ++i)
        {
            auto str = q.front();
            q.pop();
            res[index++] = atoi(str.c_str());
            // 当前元素长度不够n，末尾补充0-9，继续加入队列
            if (str.size() < n)
            {
                for (int j = 0; j <= 9; ++j)
                    q.push(str + to_string(j));
            }
        }
    }
    return res;
}

int main()
{
    auto res = printNumbers(5);
    for (auto c : res)
        cout << c << ' ';
    cout << endl;
}