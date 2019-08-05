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
#include <algorithm>

// 解法 1.
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

// 解法 2 回朔
void backtracking(std::vector<std::vector<int>> &res, std::vector<int> &sol, std::vector<int> &nums, int idx) {
  res.push_back(sol);

  for (int i = idx; i < nums.size(); i++) {
    sol.push_back(nums[i]);
    backtracking(res, sol, nums, i + 1); // pass i + 1，force next call stack use next number
    sol.pop_back(); // 回朔
  }
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  std::vector<int> sol;
  std::vector<std::vector<int>> set;
  backtracking(set, sol, nums, 0);
  return set;
}

int main() {
  std::vector<int> t = {1, 2, 3};
  auto res = subsets(t);

  return 0;
}