#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrime(i))
            count++;
    return count;
}

int countPrimes_Sieve(int n)
{
    vector<bool> isPrime;
    for (int i = 0; i < n; i++)
        isPrime.push_back(true);
    for (int i = 2; i <= sqrt(n); i++)
        if (isPrime[i])
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrime[i])
            count++;
    return count;
}

int main()
{
    cout << countPrimes_Sieve(100) << endl;
}