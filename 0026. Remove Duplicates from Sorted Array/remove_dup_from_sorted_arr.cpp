// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new
// length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra
// memory.

// Example 1:

// Given nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,2,2,3,3,4],

// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4
// respectively.

// It doesn't matter what values are set beyond the returned length.

#include <vector>

using namespace std;

// 利用 two pointers 一個前面一個後面 一樣就從 nums移除
// 只不過 vector.erase 很浪費效能
int removeDuplicates(vector<int> &nums) {
  int ptr = 0, idx = 1;
  while (idx < nums.size()) {
    if (nums[idx] == nums[ptr]) {
      nums.erase(nums.begin() + idx);
    } else {
      idx++;
      ptr++;
    }
  }
  return nums.size();
}

// 較好的解法
// 利用一個 ptr 紀錄當前不一樣的數字
// 發現不一樣就從前面取代掉該不一樣的數字
// ex. 0,0,1,1,1,2,2,3,3,4
// 以下只呈現遇到不一樣數字的時候
// =>  0,1,1,1,1,2,2,3,3,4
// =>  0,1,2,1,1,2,2,3,3,4
// =>  0,1,2,3,1,2,2,3,3,4
// =>  0,1,2,3,4,2,2,3,3,4
// 此時ptr 位置在 4 答案取長度為 5
int removeDuplicates(vector<int> &nums) {
  if (nums.size() < 1)
    return 0;

  int ptr = 0;
  for (int idx = 1; idx < nums.size(); idx++) {
    if (nums[ptr] != nums[idx]) {
      nums[++ptr] = nums[idx];
    }
  }
  return ptr + 1;
}