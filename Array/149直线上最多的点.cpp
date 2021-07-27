#include <map>
#include <vector>
using namespace std;
struct Point
{
    int x;
    int y;
};
int gcd(int a, int b)
{
    // 注意：此处如果加上判断a、b大小的逻辑会超时
    // 其实最下面👇隐含了对调a、b的功能
    /*if (a > b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }*/
    return b == 0 ? a : gcd(b, a % b);
}
int maxPoints(vector<Point> &points)
{
    // write code here
    // write code here
    int len = points.size();
    if (len <= 2)
    {
        return len;
    }
    int result = 0;
    for (int i = 0; i < len; ++i)
    {
        map<pair<int, int>, int> recordMap; // unordered_map不支持迭代器
        int dup = 1; // 自身也算一个点，另外重合点也算
        for (int j = i + 1; j < len; ++j)
        {
            int x = points[i].x - points[j].x;
            int y = points[i].y - points[j].y;
            if (x == 0 && y == 0)
            {
                ++dup;
            }
            else
            {
                int g = gcd(x, y); // 获取最大公约数
                x = x / g;
                y = y / g;
                recordMap[{x, y}]++;
            }
        }
        result = max(result, dup);
        for (auto it = recordMap.begin(); it != recordMap.end(); ++it)
        {
            result = max(result, it->second + dup);
        }
    }
    return result;
}