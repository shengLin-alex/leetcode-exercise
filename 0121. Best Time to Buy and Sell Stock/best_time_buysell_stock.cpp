// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
// Example 2:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// 根據題目
// dp(0) = 0
// dp(1) = nums[1] - nums[0], nums[1] > nums[0]
//       = 0                , nums[1] < nums[0]
// dp(i) = max(nums[i] - min[0,i-1], dp(i-1))
int maxProfit(vector<int> &prices) {
  if (prices.size() < 2)
    return 0;

  int min = INT_MAX;
  vector<int> dp(prices.size(), 0);

  for (int i = 0; i < prices.size(); i++) {
    if (i == 1)
      dp[1] = prices[1] > prices[0] ? prices[1] - prices[0] : 0;

    if (prices[i] < min)
      min = prices[i];

    if (i > 1) {
      dp[i] = max((prices[i] - min), dp[i - 1]);
    }
  }

  return dp.back();
}

int main() {
  vector<int> t = {2, 9, 5, 3, 1, 4};

  auto res = maxProfit(t);

  return res;
}