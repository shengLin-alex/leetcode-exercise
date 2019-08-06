// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number
// by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it
// loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy
// numbers.

// Example:

// Input: 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// 10 100 1000 10000 100000 ...
bool isHappy(int n) {
  unordered_set<int> hash; // 利用 hash set 來紀錄循環
  while (n != 1) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10); // 先處理餘數(個位數)
      n /= 10;                    // 除以10得到十位數 直到n == 0
    }

    n = sum;
    if (hash.count(n)) // 發現循環，表示 n 必定非 happy number
      return false;

    hash.insert(n);
  }

  return true;
}

int main(int argc, char **argv) {
  int t = stoi(string(argv[1]));
  cout << isHappy(t) << endl;

  return 0;
}