// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has
// the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <vector>

// 利用兩個動態規劃陣列來計算
// mn[i] 表示 [0, i] 最小乘積
// mx[i] 表示 [0, i] 最大乘積
// 由於整數乘以 0 最終得 0，負數乘以負數最終得到正數
// 因此每次更新[0, i - 1]最小乘積(因為可能取得最小負數)，[0, i - 1]最大乘積
// 再乘以 nums[i]，並且與nums[i] 比較(因為有可能乘積變成 0 或小於 nums[i]，此時直接捨去[0, i - 1]的乘積)
// 其中轉移方程為 =>
// mn[i] = min(mx[i - 1] * nums[i], mn[i - 1] * nums[i], nums[i])
// mx[i] = max(mx[i - 1] * nums[i], mn[i - 1] * nums[i], nums[i])
// 而最終結果 res = max(mx[i], res)
int maxProduct(std::vector<int> &nums) {
  // 注意 res 先初始為 nums[0] 也就是 mx[0]，後續再繼續與 res 比大小
  int res = nums[0], len = nums.size();
  std::vector<int> mn(len, 0), mx(len, 0);
  mn[0] = nums[0];
  mx[0] = nums[0];

  for (int i = 1; i < len; i++) {
    mn[i] = std::min(std::min(mx[i - 1] * nums[i], mn[i - 1] * nums[i]), nums[i]);
    mx[i] = std::max(std::max(mx[i - 1] * nums[i], mn[i - 1] * nums[i]), nums[i]);
    res = std::max(res, mx[i]);
  }

  return res;
}