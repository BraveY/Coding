#include <stdio.h>
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
class Solution {
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

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.countPrimes(10) << endl;
  system("pause");
  return 0;
}