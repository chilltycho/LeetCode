#include <queue>
#include <unordered_map>
using namespace std;
queue<char> q;
unordered_map<char, int> um;
//Insert one char from stringstream
void Insert(char ch)
{
    if (um.count(ch) == 0)
        q.push(ch);
    um[ch]++;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    while (!q.empty())
    {
        auto c = q.front();
        if (um[c] == 1)
            return c;
        else
            q.pop();
    }
    return '#';
}