// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

#include <vector>

// 利用動態規劃
// dp[i][j] 表示至 i j 可得到之最大正方形邊長
// => i j 設定為正方形之右下角
// => 因此我們只關心左下角左上角與右上角
// 舉例來說
// 1  1
// 1 "1"          左下角         左上角             右上角
// dp[1][1] = min(dp[1][1 - 1], dp[1 - 1][1 - 1], dp[1 - 1][1]) + 1
// 注意 取min 的目的是為了取交集，因為不允許 '0' 只允許 '1'
int maximalSquare(std::vector<std::vector<char>> &matrix) {
  if (matrix.empty() || matrix[0].empty())
    return 0;

  int m = matrix.size(), n = matrix[0].size(), res = 0;
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) // 設定邊界初始值，遇1為1遇0為0
        dp[i][j] = matrix[i][j] - '0';
      else if (matrix[i][j] == '1') {
        dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
      }

      res = std::max(res, dp[i][j]); // 取出最大值
    }
  }

  return res * res; // 回傳邊長
}