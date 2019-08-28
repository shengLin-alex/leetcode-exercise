// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum
// and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which
// is more subtle.

#include <climits>
#include <vector>

// 本題動態規劃的關鍵 : dp[i + 1] = dp[i] + nums[i + 1], if (dp[i] + nums[i + 1] > 0) 
//                             = 0, if(dp[i] + nums[i + 1] < 0)
// dp[i]表示第i個元素能取到的最大值
int maxSubArray(std::vector<int> &nums) {
  int res = INT_MIN, sum = 0;

  for (auto n : nums) {
    sum = n + (sum > 0 ? sum : 0); // sum 如果加到變成小於 0 就歸 0重新開始
    res = std::max(res, sum);
  }

  return res;
}