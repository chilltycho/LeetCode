//从数据流计算中位数
#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
  priority_queue<int, vector<int>, greater<int>> bigHalf;
  priority_queue<int, vector<int>, less<int>> smallHalf;

public:
  void addNum(int num) {
    if (bigHalf.size() >= smallHalf.size())
      smallHalf.push(num);
    else
      bigHalf.push(num);
    if (bigHalf.empty())
      return;
    if (bigHalf.top() < smallHalf.top()) {
      bigHalf.push(smallHalf.top());
      smallHalf.push(bigHalf.top());
      bigHalf.pop();
      smallHalf.pop();
    }
  }
  double findMedian() {
    int n1 = bigHalf.size();
    int n2 = smallHalf.size();
    if ((n1 + n2) % 2 == 0)
      return (bigHalf.top() + smallHalf.top()) / 2;
    return n1 > n2 ? bigHalf.top() : smallHalf.top();
  }
};

int main() {
  MedianFinder m1;
  m1.addNum(1);
  cout << m1.findMedian() << endl;
  m1.addNum(2);
  m1.addNum(5);
  cout << m1.findMedian() << endl;
}
