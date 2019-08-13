// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target
// value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

#include <vector>

// lower_bound 傾向先找左邊
int lower_bound(std::vector<int> &nums, int target) {
  int n = nums.size();
  int left = 0, right = n;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] >= target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
}

// upper_bound 傾向先找右邊
int upper_bound(std::vector<int> &nums, int target) {
  int n = nums.size();
  int left = 0, right = n;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}

// 使用 lower_bound and upper_bound 來幫助找出第一與最後
std::vector<int> searchRange(std::vector<int> &nums, int target) {
  int low = lower_bound(nums, target);
  int high = upper_bound(nums, target);

  if (low == high)
    return {-1, -1};
  else {
    return {low, high - 1};
  }
}