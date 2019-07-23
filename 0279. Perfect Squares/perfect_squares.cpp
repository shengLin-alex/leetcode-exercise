// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum
// to n.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

#include <climits>
#include <cmath>
#include <vector>

// 解法 1
// 四平方和定理
// 任何正整數都可以拆解成4個以內的平方和數
// 也就是說本題答案只有 1 2 3 4 四個可能
int numSquares(int n) {
    // 由於 2 和 8 或 3 和 12 其實是一樣的結果因此
    while (n % 4 == 0)
        n /= 4;

    // 根據四平方和定理若除以 8 餘數為 7，則該數一定只能分解成 4 個平方和
    if (n % 8 == 7)
        return 4;

    // 化簡後利用 兩數字平方和做檢查 1 或 2，都不是那就一定是 3
    for (int i = 0; i * i <= n; i++) {
        int j = sqrt(n - i * i);
        if (i * i + j * j == n) {
            return !!i + !!j; // 這段是在檢查 i j 是否為證整數
            // ex i = 任意正整數，經過一次 ! 後 變為 0 在經過一次 ! 後變為 1 即為正數
        }
    }

    return 3;
}

// 解法 2 動態規劃
// dp[i] 為正整數 i 至少能有幾個平方和組合求 dp[n]
// i 從 0 開始至 i == n 表示 0 至 n 能有幾個平方和組合
// j 從 1 開示至 i + j * j == n，表示任意正整數 i 都能加上一個 j * j
// i = 0 =>
// dp[0] = 1
// dp[1] = min(dp[0 + 1 * 1], dp[0] + 1)
// dp[4] = min(dp[0 + 2 * 2], dp[0] + 1)
int numSquares(int n) {
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i + j * j <= n; j++) {
            dp[i + j * j] = std::min(dp[i + j * j], dp[i] + 1);
        }
    }

    return dp.back();
}