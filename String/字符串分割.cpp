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
    int n;
    cin >> n;
    while (n)
    {
        string s;
        cin >> s;
        cout << s << endl;
        --n;
    }
}