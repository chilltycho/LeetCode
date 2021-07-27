#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Point
{
    Point(int xx, int yy) : x(xx), y(yy){};
    int x;
    int y;
};

int maxPoints(vector<Point> &points)
{
    // write code here
    int len = points.size();
    if (len < 3)
        return len;
    int res = 2;
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            int tmp = 2;
            long long dx = points[i].x - points[j].x;
            long long dy = points[i].y - points[j].y;
            for (int k = j + 1; k < len; ++k)
            {
                if (dx * (points[i].y - points[k].y) == dy * (points[i].x - points[k].x))
                    ++tmp;
            }
            res = max(res, tmp);
        }
    }
    return res;
}

int main()
{
    vector<Point> vi{};
    Point *a=[(-435, -347), (-435, -347), (609, 613), (-348, -267), (-174, -107), (87, 133), (-87, -27), (-609, -507), (435, 453), (-870, -747), (-783, -667), (0, 53), (-174, -107), (783, 773), (-261, -187), (-609, -507), (-261, -187), (-87, -27), (87, 133), (783, 773), (-783, -667), (-609, -507), (-435, -347), (783, 773), (-870, -747), (87, 133), (87, 133), (870, 853), (696, 693), (0, 53), (174, 213), (-783, -667), (-609, -507), (261, 293), (435, 453), (261, 293), (435, 453)];
}