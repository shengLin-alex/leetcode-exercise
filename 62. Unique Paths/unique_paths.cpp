// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
// Above is a 7 x 3 grid. How many possible unique paths are there?

// Note: m and n will be at most 100.

// Example 1:

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
// Example 2:

// Input: m = 7, n = 3
// Output: 28

#include<vector>

// dp(n, 1) = 1
// dp(1, m) = 1
// dp(n, m) = dp(n, m - 1) + dp(n - 1, m)
int uniquePaths(int m, int n) {
    if (m < 2 || n < 2) return 1;

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    for (int i = 0; i < m; i++) dp[0][i] = 1;
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    auto res = uniquePaths(90, 23);

    return 0;
}