// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For
// each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3.
// Output: 5
// Explanation:

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.
// Note:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.

#include <unordered_map>
#include <vector>

// 最佳解
// 化簡題目法
class Solution {
public:
  // P: 正; N: 負
  //                   sum(P) - sum(N) = target
  // sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
  //                        2 * sum(P) = target + sum(nums)
  // =>                         sum(P) = (target + sum(nums)) / 2
  // 變成背包問題：給一數組求和為(target + sum(nums)) / 2的情況有幾種，每種數字只能用一次
  int findTargetSumWays(std::vector<int> &nums, int S) {
    int sum = 0;
    for (auto n : nums)
      sum += n;

    return (sum < S || (sum + S) % 2 > 0) ? 0 : subsetSum(nums, (sum + S) / 2);
  }

  // 背包問題
  // dp[i][j] = dp[i - 1][j] (j < nums[i]) 總和小於第i個數字，因此到第i - 1時已經達到j
  // dp[i][j] = dp[i][j] + dp[i - 1][j - nums[i]] (j >= nums[i])
  //            總和大於第i個數字，因此為到第i個數，總和達到j的情況加上到第i - 1個數總和達到 j-nums[i]的情況
  //
  // dp[i][j] means number of ways to get sum j with first i elements from nums.
  // 藉由從後向前計算來取得上一列(dp[i-1])的結果，因此 reduce => dp[j] = dp[j] + dp[j - nums[i]]
  int subsetSum(std::vector<int> &nums, int S) {
    std::vector<int> dp(S + 1, 0);
    dp[0] = 1;
    for (int n : nums)
      for (int i = S; i >= n; i--)
        dp[i] += dp[i - n];

    return dp[S];
  }
};

// // dfs 複雜度為 O(2^N)
// void helper(std::vector<int>& nums, int S, int start, int& res) {
//     if (start >= nums.size()) {
//         if (S == 0) res++;

//         return;
//     }

//     helper(nums, S + nums[start], start + 1, res);
//     helper(nums, S - nums[start], start + 1, res);
// }

// int findTargetSumWays(std::vector<int>& nums, int S) {
//     int res = 0;
//     helper(nums, S, 0, res);

//     return res;
// }

// 二階動態規劃法
// dp[i][j] means: the ways that from start to i sum as j
// dp[0][0] = 1;
// dp[i + 1][j + nums[i]] += dp[i][j];
// dp[i + 1][j - nums[i]] += dp[i][j];
int findTargetSumWays(std::vector<int> &nums, int S) {
  const int N = nums.size();
  std::vector<std::unordered_map<int, int>> dp(N + 1);
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (auto m : dp[i]) {
      dp[i + 1][m.first + nums[i]] += m.second;
      dp[i + 1][m.first - nums[i]] += m.second;
    }
  }

  return dp[N][S];
}

int main() {
  std::vector<int> t = {1, 1, 1, 1, 1};
  auto r = findTargetSumWays(t, 3);

  return 0;
}