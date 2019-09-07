// Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

// Example 1:
// Input: [1,3,5,4,7]
// Output: 3
// Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
// Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
// Example 2:
// Input: [2,2,2,2,2]
// Output: 1
// Explanation: The longest continuous increasing subsequence is [2], its length is 1.

#include <vector>

// 利用 two pointer
// 快慢指針 快指針 j 持續檢查 j 與 j - 1
// 當快指針檢查發現非遞增時將慢指針位置更新至 j
int findLengthOfLCIS(std::vector<int> &nums) {
  int n = nums.size(), r = 0;
  if (n < 1)
    return 0;

  if (n < 2)
    return 1;

  int i = 0, j = 0;
  while (i < n && j < n) {
    if (j > 0 && nums[j] <= nums[j - 1])
      i = j;

    r = std::max(r, j - i + 1);
    ++j;
  }

  return r;
}

int main() {
  std::vector<int> t = {1,3,5,3,4,5,6,7,1,2,3};
  auto r = findLengthOfLCIS(t);

  return 0;
}