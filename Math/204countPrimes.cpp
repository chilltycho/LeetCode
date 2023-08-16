#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}

int countPrimes(int n) {
  int count = 0;
  for (int i = 2; i < n; i++)
    if (isPrime(i))
      count++;
  return count;
}
//埃氏筛，如果x是质数，则2x,3x..一定不是质数。优化，直接从x*x开始标记，因为2x,3x..一定在x之前被其他数的倍数标记过了
int countPrimes_Sieve(int n) {
  vector<bool> isPrime(n, true); //默认全是质数
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
//线性筛,让每个合数只标记一次。45同时被3,5两个数标记
int countPrimes_3(int n) {
  vector<int> primes;
  vector<int> isPrime(n, 1);
  for (int i = 2; i < n; i++) {
    if (isPrime[i])
      primes.push_back(i);
    for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
      isPrime[i * primes[j]] = 0;
      if (i % primes[j] ==
          0) //对合数y=x*primes[j],一定在遍历到x/primes[j]*primes[j]时被标记
      {
        break;
      }
    }
  }
  return primes.size();
}
int main() { cout << countPrimes_3(100) << endl; }

