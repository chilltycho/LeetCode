//求高度数组能组成最大矩形面积
#include <cassert>
#include <climits>
#include <stack>
#include <vector>
using namespace std;
//以每列高度为长的最大面积
int largestRectangleArea(vector<int> &heights) {
  int len = heights.size() - 1;
  if (len == 0)
    return 0;
  int res = 0;
  for (int i = 0; i <= len; i++) {
    int left = i;
    int curHeight = heights[i];
    while (left > 0 && heights[left - 1] >= curHeight)
      left--;
    int right = i;
    while (right < len - 1 && heights[right + 1] >= curHeight)
      right++;
    res = max(res, curHeight * (right - left + 1));
  }
  return res;
}

//单调递增栈
int largestRectangleArea_2(vector<int> &heights) {
  if (heights.empty()) {
      return 0;
    }
    if (heights.size() == 1) {
      return heights[0];
    }
    int result = 0;
    stack<int> st;
    heights.insert(heights.begin(), 0); // 哨兵，确保栈不为空
    heights.push_back(0);               // 哨兵，确保都能弹出
    for (int i = 0; i < heights.size(); i++) {
      while (st.size() && heights[i] < heights[st.top()]) {
        // 可计算高度
        int mid = st.top();
        st.pop();
        // 宽度开始索引
        int l_i = st.top();
        int width = i - l_i - 1;
        result=max(result,width*heights[mid]);
      }
      st.push(i);
    }
    return result;
}

int main() {
  vector<int> vi{2, 1, 5, 6, 2, 3};
  assert(10 == largestRectangleArea_2(vi));
}

