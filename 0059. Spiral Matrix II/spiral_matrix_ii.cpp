// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// Example:

// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <vector>

// 與上一題 0054 的思路相同，遍歷方法一樣，只是改成填值
// while 迴圈設定為 item <= n * n，item 即為我們要填入的值
std::vector<std::vector<int>> generateMatrix(int n) {
  std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
  int up = 0, down = n - 1, left = 0, right = n - 1, item = 1;

  while (item <= n * n) {
    for (int i = left; i <= right && item <= n * n; i++) {
      res[up][i] = item++;
    }

    for (int i = up + 1; i <= down - 1 && item <= n * n; i++) {
      res[i][right] = item++;
    }

    for (int i = right; i >= left && item <= n * n; i--) {
      res[down][i] = item++;
    }

    for (int i = down - 1; i >= up + 1 && item <= n * n; i--) {
      res[i][left] = item++;
    }

    up++;
    down--;
    left++;
    right--;
  }

  return res;
}