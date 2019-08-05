// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include <vector>
#include <algorithm>

// 解法 1 與 0078 一樣思路
// 但須判斷重複數字並跳過
std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
  if (nums.empty())
    return {};

  std::sort(nums.begin(), nums.end()); // 由於必須判斷處理過數字與下一個數字是否重複因此利用排序
  std::vector<std::vector<int>> res(1);
  int skip = 1, last = nums[0];
  for (int i = 0; i < nums.size(); i++) {
    if (last != nums[i]) {
      last = nums[i];
      skip = res.size();
    }

    int back_size = res.size();
    for (int j = back_size - skip; j < back_size; j++) {
      res.push_back(res[j]);         // 再push一次自己
      res.back().push_back(nums[i]); // 對最後一組 set 再 push 目前數字
    }
  }

  return res;
}

// 解法 2 回朔
void backtracking(std::vector<std::vector<int>> &res, std::vector<int> &sol, std::vector<int> &nums, int idx) {
  res.push_back(sol);
  for (int i = idx; i < nums.size(); i++) {
    sol.push_back(nums[i]);
    backtracking(res, sol, nums, i + 1);
    sol.pop_back();

    // 檢查當前數字與下一個數字是否相同 相同則須跳過
    while (i < nums.size() - 1 && nums[i] == nums[i + 1])
      i++;
  }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
  if (nums.empty())
    return {};

  std::sort(nums.begin(), nums.end()); // 由於必須判斷處理過數字與下一個數字是否重複因此利用排序
  std::vector<std::vector<int>> res;
  std::vector<int> sol;
  backtracking(res, sol, nums, 0);

  return res;
}