#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s{"dog cat monkey"};
    stringstream ss{s};
    string tmp;
    while (ss >> tmp)
        cout << tmp << endl;
}