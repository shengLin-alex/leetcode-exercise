// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// Example:

// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Note:

// You can assume that you can always reach the last index.

#include <vector>

int jump(std::vector<int> &nums) {
  // 設定 res 為所需步數 cur 為當前所能到達最遠位置 pre 為前一步能到達之最遠位置 i 為計數實際往前的距離
  int res = 0, len = nums.size(), cur = 0, i = 0;
  while (cur < len - 1) { // cur 未抵達終點 (len - 1) 時都必須進入 loop
    res++;                // 往前跳一次

    int pre = cur;
    while (i <= pre) { // i 小於等於 pre 時表示目前位置尚在上一次的最遠距離範圍內
      cur = std::max(cur, i + nums[i]);
      i++;
    }

    if (pre == cur) // 表示 cur 未被更新無法到達終點
      return -1;
  }

  return res;
}