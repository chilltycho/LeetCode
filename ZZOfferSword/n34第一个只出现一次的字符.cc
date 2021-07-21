#include <string>
using namespace std;
int FirstNotRepeatingChar(string str)
{
    int map[128]{};
    for (auto c : str)
        ++map[c];
    for (int i = 0; i < str.size(); ++i)
        if (map[str[i]] == 1)
            return i;
    return -1;
}