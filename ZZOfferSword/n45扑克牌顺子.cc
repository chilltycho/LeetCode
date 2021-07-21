#include <vector>
#include <algorithm>
using namespace std;
bool IsContinuous(vector<int> numbers)
{
    if (numbers.empty())
        return false;
    sort(numbers.begin(), numbers.end());
    int p0 = 0;
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        if (numbers[i] == 0)
        {
            ++p0;
            continue;
        }
        while (numbers[i] + 1 != numbers[i + 1])
        {
            if (p0 <= 0)
                return false;
            ++numbers[i];
            --p0;
        }
    }
    return true;
}