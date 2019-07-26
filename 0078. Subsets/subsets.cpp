// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <iostream>
#include <vector>

// 從空集合開始分別往內塞入每個元素
std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  std::vector<std::vector<int>> set(1);
  int len = nums.size();
  for (int i = 0; i < len; i++) {
    int setlen = set.size();
    for (int j = 0; j < setlen; j++) {
      set.push_back(set[j]);         // 把之前的集合塞回去
      set.back().push_back(nums[i]); // 再對每個"之前的"集合塞目前的元素
    }
  }
  return set;
}

int main() {
  std::vector<int> t = {1, 2, 3};
  auto res = subsets(t);

  return 0;
}