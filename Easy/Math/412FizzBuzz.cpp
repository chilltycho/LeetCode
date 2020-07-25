#include <iostream>
#include <vector>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> vs;
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
            vs.push_back("FizzBuzz");
        else if (i % 3 == 0)
            vs.push_back("Fizz");
        else if (i % 5 == 0)
            vs.push_back("Buzz");
        else
            vs.push_back(to_string(i));
    }
    return vs;
}