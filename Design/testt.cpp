#include <memory>
#include <iostream>
using namespace std;

int main()
{
    int x = 42;
    auto m = [&x]()
    { cout << x << endl; };
    x = 7;
    m();
}