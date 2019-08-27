// You are given coins of different denominations and a total amount of money amount. Write a function to compute the
// fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
// combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <vector>

// 一開始以為是 greedy
// 但其實是動態規劃的題目(求最少需要幾個硬幣，極值問題)
// 定義 dp[i] = min(dp[i], dp[i - coin[j]] + 1)
// 其中 dp[i] 代表至 i 元最少有幾個硬幣
// dp[i - coin[j]] 表示，減去其中一種硬幣的值後最少有幾個硬幣
// 轉移方程可以看為(假設 coin[j] = 5) => dp[11] = min(dp[11], dp[11 - 5] + 1)
// 意思就是 dp[6]的時候再加一個硬幣(5元)後可得11元
int coinChange(std::vector<int> &coins, int amount) {
  // 此處初始化 amount + 1個，dp[0]必須設為0，其餘可設為 amount + 1，例如amount為11，全部用1元等於11個硬幣，再+1變為不可能出現的數
  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;
  int len = coins.size();

  for (int i = 1; i <= amount; i++) {
    for (int j = 0; j < len; j++) {
      if (coins[j] <= i) // 幣值須小於當前總額不然會爆
        dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
    }
  }

  return dp[amount] > amount ? -1 : dp[amount];
}