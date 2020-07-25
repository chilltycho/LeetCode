#include <vector>
#include <iostream>
using namespace std;

void reverseString(vector<char> &s)
{
    int ssize = s.size();
    for (int i = 0; i < ssize / 2; i++)
    {
        char temp = s[i];
        s[i] = s[ssize - i-1];
        s[ssize - i-1] = temp;
    }
}

int main()
{
    vector<char> vc{'h', 'e', 'l', 'l', 'o'};
    reverseString(vc);
    for (auto c : vc)
        cout << c << ' ';
}