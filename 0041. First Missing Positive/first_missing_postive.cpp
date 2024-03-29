// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1

// Note. Your algorithm should run O(n) time and uses O(1) space

#include <climits>
#include <cmath>
#include <vector>

// 由於答案絕對小於等於陣列的長度
// 所以利用陣列位置來幫助紀錄
// ex. 1 2 3 4 5 6 7 9
// 最後的數字不管多大，答案都是 8

// 標記 0 與負數為一個絕對不可能出現的數字
// 接著檢查一次陣列找出小於陣列長度的數字
// 若該數字前一個數大於0則標記為負，此時 nums[indexof(that number > 0)] < 0 表明 (indexof(the number > 0) + 1)
// 這個數字存在於 nums 最後再遍厲一次陣列取得某一個位置是否大於0，大於0表示 indexof(the number > 0) 這個數字不存在 nums
// 即為答案
int firstMissingPostive(std::vector<int> &nums) {
  for (int &n : nums) {
    if (n <= 0 || n > nums.size()) {
      n = INT_MAX;
    }
  }

  for (int &n : nums) {
    int a = abs(n);
    if (a <= nums.size()) {
      if (nums[a - 1] > 0) {
        nums[a - 1] *= -1;
      }
    }
  }

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0)
      return i + 1;
  }

  return nums.size() + 1;
}

int main() {
  std::vector<int> t = {1, 3, 4, 5, 6, 7, 8, 10};
  auto r = firstMissingPostive(t);

  return 0;
}