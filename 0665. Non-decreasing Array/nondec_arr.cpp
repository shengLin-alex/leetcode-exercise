// Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1
// element.

// We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

// Example 1:
// Input: [4,2,3]
// Output: True
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:
// Input: [4,2,1]
// Output: False
// Explanation: You can't get a non-decreasing array by modify at most one element.
// Note: The n belongs to [1, 10,000].

#include <vector>

// "4" 2 3
// 1 "4" 2 3
// 2 3 3 "2" 4
// 引號內為被修改的數字
// 由上面例子可看出，發生衝突時被修改的數字可能為當前數字也可能為前一數字
bool checkPossibility(std::vector<int> &nums) {
  int cnt = 1, n = nums.size();
  for (int i = 1; i < n; i++) {
    if (nums[i] < nums[i - 1]) { // 發生衝突(當前數小於前一個數)
      if (cnt == 0) // 檢查是否已經改過一次，是的話 return false
        return false;

       // 前一個數剛好是陣列第一個數時或者當前數字大於等於前前個數字時
      if (i == 1 || nums[i] >= nums[i - 2])
        nums[i - 1] = nums[i]; // 將前一個數更新為自己
      else // 否則將自己更新為前一個數
        nums[i] = nums[i - 1];

      cnt--;
    }
  }

  return true;
}