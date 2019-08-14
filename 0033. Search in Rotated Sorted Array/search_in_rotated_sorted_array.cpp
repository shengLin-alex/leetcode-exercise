// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include <vector>

// 0    1    2    4    5    6    7

// 7    0    1    2    4    5    6

// 6    7    0    1    2    4    5

// 5    6    7    0    1    2    4

// 4    5    6    7    0    1    2

// 2    4    5    6    7    0    1

// 1    2    4    5    6    7    0
// 觀察上表可以發現，中點若小於最右邊的數，則[mid, right] 有序
// 反之，[left, mid] 有序
int search(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
      return mid;

    if (nums[mid] < nums[right]) {                     // 右半有序
      if (nums[mid] < target && nums[right] >= target) // 找右邊
        left = mid + 1;
      else // 找左邊
        right = mid - 1;
    } else {                                          // 左半有序
      if (nums[mid] > target && nums[left] <= target) // 找左邊
        right = mid - 1;
      else // 找右邊
        left = mid + 1;
    }
  }

  return -1;
}