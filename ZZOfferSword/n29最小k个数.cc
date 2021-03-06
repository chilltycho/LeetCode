#include <vector>
using namespace std;
int partition(vector<int> &input, int l, int r)
{
    int p = input[l];
    int lt = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (input[i] < p)
        {
            lt++;
            swap(input[i], input[lt]);
        }
    }
    swap(input[l], input[lt]);
    return lt;
}
void select(vector<int> &input, int l, int r, int k)
{
    if (l >= r)
        return;
    int po = partition(input, l, r);
    int num = po - l + 1;
    if (num == k)
        return;
    else if (num < k)
        select(input, po + 1, r, k);
    else
        select(input, l, po - 1, k);
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> res;
    if (k > input.size())
        return res;
    select(input, 0, input.size() - 1, k);
    for (int i = 0; i < k; i++)
        res.push_back(input[i]);
    return res;
}