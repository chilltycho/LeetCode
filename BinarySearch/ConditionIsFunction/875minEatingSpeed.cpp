//共piles.size()堆，每堆piles[i]。求可在H小时内吃完所有的最小速度K(整数)
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

int cal(vector<int> &piles, int sp) {
  int res = 0;
  for (auto p : piles) {
    if (p < sp)
      ++res;
    else {
      int remain = p % sp;
      if (remain > 0)
        res += p / sp + 1;
      else
        res += p / sp;
    }
  }
  return res;
}

/*吃速度越小，耗时越多，速度越大，耗时越小，单调性。*/
int minEatingSpeed(vector<int> &piles, int H) {
  int maxVal = *max_element(piles.begin(), piles.end());
  int left = 1;       //最小速度
  int right = maxVal; //最大速度
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (cal(piles, mid) > H) //耗时太多
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int main() {
  vector<int> piles{3, 6, 7, 11};
  assert(4 == minEatingSpeed(piles, 8));

  vector<int> piles2{30, 11, 23, 4, 20};
  assert(30 == minEatingSpeed(piles2, 5));
}