#include <queue>
#include <iostream>
using namespace std;
bool backspaceCompare(string s, string t)
{
    auto compare = [](pair<int, int> &a, pair<int, int> &b)
    { return a.first < b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
    
}

int main()
{
    string s{"xywrrmp"};
    string t{"xywrrmu#p"};
    cout << backspaceCompare(s, t) << endl;
}