// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right
// corner of the grid (marked 'Finish' in the diagram below).

// https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Note: m and n will be at most 100.

// Example 1:

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

#include <vector>

// 遇到障礙物不累加
// 由於跟 unique paths i 不同，不能將 dp[0][n] 設為 1;dp[m][0] 設為 1
// 因此將 dp 擴充為 (m + 1) * (n + 1) 為了應付邊緣障礙物的狀況
int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
  if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
    return 0;

  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  std::vector<std::vector<long>> dp(m + 1, std::vector<long>(n + 1, 0)); // 使用 long 避免 int 溢位
  // dp[1][1](真正的起點) = 1 => dp[1][1] = dp[0][1] + dp[1][0]，因此初始化 dp[0][1] or dp[1][0] = 1 任一即可
  dp[0][1] = 1;

  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (obstacleGrid[i - 1][j - 1] != 0) // 跳過障礙物
        continue;

      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m][n];
}