// Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After
// partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning.

// Example 1:

// Input: A = [1,15,7,9,2,5,10], K = 3
// Output: 84
// Explanation: A becomes [15,15,15,9,10,10,10]

// Note:

// 1 <= K <= A.length <= 500
// 0 <= A[i] <= 10^6

#include <climits>
#include <vector>

// 利用動態規劃
// dp[i] = max sum of A[0] ~ A[i]
int maxSumAfterPartitioning(std::vector<int> &A, int K) {
  int n = A.size();
  std::vector<int> dp(n + 1, 0); // 取 n + 1，方便後續處理，省下 padding

  for (int i = 1; i <= n; i++) {
    int cur_max = INT_MIN;
    // j 從 1 開始至min(i, K)，子陣列最短需要一個元素且不得超過 i 與題目所限制之 K
    for (int j = 1; j <= std::min(i, K); j++) {
      cur_max = std::max(cur_max, A[i - j]); // 取出當前最大數字
      dp[i] = std::max(
          dp[i],
          dp[i - j] + cur_max * j); // 更新 dp，在 j 取 partition 時的 cur_max 乘以 j 的個數，並與當前 dp[i] 比較取大
    }
  }

  return dp[n];
}

int main() {
  std::vector<int> t = {1,15,7,9,2,5,10};
  auto r = maxSumAfterPartitioning(t, 3);

  return 0;
}