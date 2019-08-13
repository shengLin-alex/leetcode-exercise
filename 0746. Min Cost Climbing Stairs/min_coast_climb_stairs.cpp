// On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

// Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the
// floor, and you can either start from the step with index 0, or the step with index 1.

// Example 1:
// Input: cost = [10, 15, 20]
// Output: 15
// Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
// Example 2:
// Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// Output: 6
// Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
// Note:
// cost will have a length in the range [2, 1000].
// Every cost[i] will be an integer in the range [0, 999].

#include <vector>

// 動態規劃
// 定義 dp[i] = 到第 i 階階梯 且包含第 i 階 cost 之最小 cost
// dp[0] = cost[0]
// dp[1] = cost[1]
// dp[i] = "cost[i]" + min(dp[i - 1], dp[i - 2])
// 注意！由於最終階梯可由前兩階或前一階完成，因此 return min(dp[n - 1], dp[n - 2])
// n = cost.size()
int minCostClimbingStairs(std::vector<int> &cost) {
  int n = cost.size();
  std::vector<int> dp(cost.size(), 0);

  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i < cost.size(); i++) {
    dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
  }

  return std::min(dp[n - 1], dp[n - 2]);
}

int main() {
  std::vector<int> t = {10, 15, 20, 9};
  auto r = minCostClimbingStairs(t);

  return 0;
}