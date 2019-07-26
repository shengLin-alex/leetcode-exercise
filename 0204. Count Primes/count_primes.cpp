// Count the number of prime numbers less than a non-negative number, n.

// Example:

// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

#include <vector>

// O(n^1.5)
// 從 2 開始取尚未被標記的數字，並往後標記該未被標記的數字之倍數
// 最後剩下沒有被標記的數字就是質數
int countPrimes(int n) {
  int res = 0;
  std::vector<bool> marks(n, false);

  for (int i = 2; i < n; i++) {
    if (!marks[i]) {
      res++;

      for (int j = 2; i * j < n; j++) {
        marks[j * i] = true;
      }
    }
  }

  return res;
}