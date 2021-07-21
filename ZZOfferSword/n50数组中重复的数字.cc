#include<vector>
using namespace std;
int duplicate(vector<int> &numbers)
{
    // write code here
    if (numbers.empty())
        return -1;
    for (int i = 0; i < numbers.size(); ++i)
    {
        while (numbers[i] != numbers[numbers[i]])
            swap(numbers[i], numbers[numbers[i]]);
    }
    for (int i = 0; i < numbers.size(); ++i)
        if (numbers[i] != i)
            return numbers[i];
    return -1;
}