// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example:

// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

#include<vector>
#include<algorithm>

// dp(1, m) = sum(dp[0][0] ~ dp[0][m - 1])
// dp(n, 1) = sum(dp[0][0] ~ dp[n - 1][0])
// dp(n, m) = min(dp(n, m - 1), dp(n - 1, m))
int minPathSum(std::vector<std::vector<int>>& grid) {
    if (grid.size() < 1) return 0;

    int m = grid[0].size(), n = grid.size(), sum = 0;
    std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), 0));

    for (int i = 0; i < m; i++) {
        sum += grid[0][i];
        dp[0][i] = sum;
    }

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += grid[i][0];
        dp[i][0] = sum;
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    return dp[n - 1][m - 1];
}

int main() {
    std::vector<std::vector<int>> t = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    auto r = minPathSum(t);

    return 0;
}