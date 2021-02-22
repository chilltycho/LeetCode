#include <iostream>
#include <random>
#include <vector>
using namespace std;
//洗牌：保证结果有n!种可能性，
int randint(int low, int high)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    return dis(gen);
}

class Solution
{
private:
    vector<int> nu;
    vector<int> backup;

public:
    Solution(vector<int> &nums)
    {
        nu = nums;
        backup = nums;
    }
    vector<int> reset()
    {
        return backup;
    }
    vector<int> shuffle()
    {
        int n = nu.size();
        for (int i = 0; i < n; i++)
        {
            int rnd = randint(i, n - 1);
            swap(nu[i], nu[rnd]);
        }
        return nu;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    Solution so(nums);
    for (const auto c : so.shuffle())
        cout << c << ' ';
    cout << endl;
    for (const auto c : so.reset())
        cout << c << ' ';
    cout << endl;
    for (const auto c : so.shuffle())
        cout << c << ' ';
}