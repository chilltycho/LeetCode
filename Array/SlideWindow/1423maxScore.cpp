//几张牌排成一行，只能从两端拿，拿k张牌，求能获得最大点数
#include <vector>
#include <cassert>
#include <numeric>
#include <iostream>
using namespace std;
//剩下的数组一定连续，和最小
int maxScore(vector<int> &cardPoints, int k)
{
    int len = cardPoints.size();
    int allSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    if (k == len)
        return allSum;

    int windowSize = len - k;
    int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
    int ans = sum;
    for (int i = 0; i < k; ++i)
    {
        sum = sum - cardPoints[i] + cardPoints[windowSize + i];
        ans = min(ans, sum);
    }
    return allSum - ans;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 1}; //1,6,5
    assert(12 == maxScore(vi, 3));
    vector<int> vi1{2, 2, 2};
    assert(4 == maxScore(vi1, 2));
    vector<int> vi2{1, 79, 80, 1, 1, 1, 200, 1};
    assert(202 == maxScore(vi2, 3));
}