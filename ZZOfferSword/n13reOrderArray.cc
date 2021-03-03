#include <iostream>
#include <vector>
using namespace std;
vector<int> reOrderArray(vector<int> &array)
{
    vector<int> od;
    vector<int> ev;
    for (auto c : array)
    {
        if (c & 1)
            od.push_back(c);
        else
            ev.push_back(c);
    }
    for (auto c : ev)
        od.push_back(c);
    return od;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 5, 5};
    reOrderArray(vi);
    for (auto c : vi)
        cout << c << ' ';
    cout << endl;
}