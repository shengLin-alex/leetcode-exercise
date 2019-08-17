// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// Example 1:

// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

#include <vector>

// 解法1
// 利用動態規劃
// dp[i] 表示到達位置 i 後所剩餘之最大步數
// 到達前一個位置所剩餘最大步數比較到達前一個位置所獲得之 max jump length取較達值再 - 1
// 注意：減去 1 的意思是因為到達前一個位置後要再移動一步才會到達當前位置
// => dp[i] = max(dp[i - 1], nums[i - 1]) - 1
// 過程中若發現dp[i] 的值小於0，即表示無法完成跳躍
bool canJump(std::vector<int> &nums) {
  std::vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    dp[i] = std::max(dp[i - 1], nums[i - 1]) - 1;
    if (dp[i] < 0)
      return false;
  }

  return true;
}

// 解法2
// 貪心算法
// 由於我們只需要關注是否能抵達最後一個位置，因此維護一個變數 reach，用以表示遍歷到之位置能獲得之最遠跳躍位置
bool canJump(std::vector<int> &nums) {
  int reach = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
    if (i > reach || reach >= n - 1) // 兩種狀況 i > reach，表示該位置無法抵達，reach >= n - 1 表示已經抵達終點
      break;

    reach = std::max(reach, i + nums[i]);
  }

  return reach >= n - 1;
}