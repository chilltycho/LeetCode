/*给定n个非负整数a1,a2...an，每个数代表坐标中一个点[i,ai]，在坐标系内画垂直线。找出其中两条线，
使得它们与x轴共同构成的容器可以容纳最多的水。面积只与两柱子有关
输入：[1,8,6,2,5,4,8,3,7]
输出：49*/
#include <iostream>
#include <vector>
using namespace std;
// 头尾双指针，一边小时移动该边。正确性：数组中所有位置可作为容器边界
int maxArea(vector<int> &height) {
  if (height.size() < 2)
    return 0;
  int res = 0;
  int i = 0;
  int j = height.size() - 1;
  while (i < j) {
    int area = (j - i) * min(height[i], height[j]);
    res = max(res, area);
    if (height[i] > height[j]) {
      j--;
    } else {
      i++;
    }
  }
  return res;
}
// 暴力法，遍历所有边界情况
int maxArea_vio(vector<int> &height) {
  int res = 0;
  for (int i = 0; i < height.size() - 1; i++) {
    for (int j = i + 1; j < height.size(); j++) {
      int area = (j - i) * min(height[i], height[j]);
      res = max(area, res);
    }
  }
  return res;
}

int main() {
  vector<int> vi{1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << maxArea_vio(vi);
}