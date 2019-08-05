// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Note:

// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?

#include <vector>

// 利用動態規劃
// dp(i) 代表至 nums[i] 之 LIS length
// 搭配巣狀for loop
// 達到類似暴力法的效果
int lengthOfLIS(std::vector<int> &nums) {
  std::vector<int> dp(nums.size(), 1);
  int res = 0;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < i; j++)
      if (nums[i] > nums[j])
        // 轉移方程 => 至 i LIS 與當前最靠近 i 且小於 i 並加上1(也就是 i) 相比取較大值
        dp[i] = std::max(dp[i], dp[j] + 1);

    res = std::max(dp[i], res);
  }

  return res;
}