#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
vector<string> split(string &s, char delim)
{
    stringstream ss(s);
    vector<string> res;
    string item;
    while (getline(ss, item, delim))
        res.push_back(item);
    return res;
}
int main()
{
    string s{"172.16.254.1."};
    auto res = split(s, '.');
    for (auto c : res)
        cout << c << ' ';
    cout << res.size();
}