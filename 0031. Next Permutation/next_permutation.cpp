// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending
// order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand
// column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
// 0,5,1 → 1,0,5

#include <algorithm>
#include <vector>

// 從後往前看 第一個降冪的起點為 7 而第一個縮小的數字為 2
// 1 "2" 7 4 3 1
// 從後往前看 第一個比 2 大的數為 3
// 1 "2" 7 4 "3" 1
// 2 3 交換位置
// 1 "3" 7 4 "2" 1
// 3 以後的數字升冪排序，但由於可以確定3以後的數字為升冪排序，因此3以後的數字直接反轉即可
// 1 3 1 2 4 7
void nextPermutation(std::vector<int> &nums) {
  int i, j, n = nums.size();

  for (i = n - 2; i >= 0; i--) { // 從倒數第二的數字開始跑，因為最後一個數字檢查不了
    if (nums[i + 1] > nums[i]) {
      for (j = n - 1; j > i; j--) // 從最後一個數字開始找比第一個縮小的數大的數字
        if (nums[j] > nums[i])
          break;

      std::swap(nums[i], nums[j]);
      // 反轉第一個縮小的數字的位置的下一個位置至最後
      std::reverse(nums.begin() + i + 1, nums.end());
      return;
    }
  }

  // 如果前面的處理都沒用的話 表示該數已經是最大 直接反轉
  std::reverse(nums.begin(), nums.end());
}