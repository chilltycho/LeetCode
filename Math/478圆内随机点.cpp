// 给定圆半径和圆心的x，y坐标，写个在圆中产生均匀随机点的函数
#include <random>
using namespace std;
class Solution {
public:
  double rad, xc, yc;
  mt19937 rng{random_device{}()};
  uniform_real_distribution<double> uni{0, 1};

  Solution(double radius, double x_center, double y_center) {
    rad = radius, xc = x_center, yc = y_center;
  }
  vector<double> randPoint() {
    double d = rad * sqrt(uni(rng));      // 到圆心距离
    double theta = uni(rng) * (2 * M_PI); // 与水平轴夹角
    return {d * cos(theta) + xc, d * sin(theta) + yc};
  }

  // 在正方形内采样，利用拒绝采样
  vector<double> randPoint_1() {
    double x0 = xc - rad;
    double y0 = yc - rad;
    while (true) {
      double xg = x0 + uni(rng) * 2 * rad;
      double yg = y0 + uni(rng) * 2 * rad;
      if (pow((xg - xc), 2) + pow((yg - yc), 2) <= rad * rad)
        return {xg, yg};
    }
  }
};

