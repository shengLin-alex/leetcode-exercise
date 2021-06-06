// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []

#include <vector>
#include <algorithm>

// 固定一個數字後用 two pointer 定位
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> res;
  std::sort(nums.begin(), nums.end());

  // 已排序後最後一個數字小於零表示整串數字皆小於零不可能會有答案
  // 同樣第一個數字大於零表示整串數字皆大於零
  if (nums.empty() || nums.back() < 0 || nums.front() > 0 || nums.size() < 3)
    return {};

  // 因答案組合需三個數字，因此可作固定的數字不會是整串數字的最後兩個
  for (int k = 0; k < nums.size() - 2; k++) {
    if (nums[k] > 0)
      break;

    // 已經固定過 不需再次處理
    if (k > 0 && nums[k] == nums[k - 1])
      continue;

    int target = 0 - nums[k], i = k + 1, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] == target) {
        res.push_back({ nums[k], nums[i], nums[j] });

        // 持續跳過當前 i j 重複之數字 避免重複解出現
        while (i < j && nums[i] == nums[i + 1])
          i++;

        while (i < j && nums[j] == nums[j - 1])
          j--;

        i++;
        j--;
      } else if (nums[i] + nums[j] < target) { // 相加後尚不足 需向右邊找更大的數字
        i++;
      } else { // 相加後太大 向左邊找更小的數字
        j--;
      }
    }
  }

  return res;
}