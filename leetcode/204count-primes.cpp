#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 536 ms, faster than 14.47% of C++ online submissions for Count Primes.
Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Count
Primes.
 */
class Solution1 {
 public:
  int countPrimes(int n) {
    if (n <= 1) return 0;
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime(i)) {
        count++;
      }
    }
    return count;
  }

 private:
  bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }
};

/*
Runtime: 24 ms, faster than 91.29% of C++ online submissions for Count Primes.
Memory Usage: 9.8 MB, less than 16.67% of C++ online submissions for Count
Primes. 使用vector 为80ms 8.7Mb
质数筛选法：i 是质数的话， 2*i，3*i都不是质数，因此不用再判断
 */
class Solution2 {
 public:
  int countPrimes(int n) {
    if (n <= 1) return 0;
    int count = 0;
    // vector<bool> prime(n, true);
    bool prime[n];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i < n; i++) {
      if (prime[i]) {
        for (int64_t j = int64_t(i) * i; j < n;
             j = i + j) {  //从2i开始叠加 会重复一些，为什么从i*i 平方开始？
          prime[j] = false;
        }
      }
    }
    for (int i = 2; i < n; i++) {
      if (prime[i]) count++;
    }
    return count;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  cout << sol.countPrimes(46340) << endl;
  system("pause");
  return 0;
}