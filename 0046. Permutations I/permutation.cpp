// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <iostream>
#include <vector>
using namespace std;

// 利用回朔
// 用一個 bool 陣列紀錄某一個數字是否已經使用過
void backtracking(std::vector<std::vector<int>> &res, std::vector<int> &tmp, std::vector<bool> &used,
                  std::vector<int> &nums, int dimension) {
  if (dimension == nums.size()) { // dimension 為 nums.size()時表示 tmp此時為一組解
    res.push_back(tmp);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (used[i])
      continue; // 第 i 個數已經使用過 continue

    used[i] = true; // 設為已經使用
    tmp.push_back(nums[i]);
    backtracking(res, tmp, used, nums, dimension + 1);
    tmp.pop_back();  // 回朔
    used[i] = false; // 準備找下一組解時 要將是否使用過設定回來
  }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums) {
  std::vector<std::vector<int>> res;
  std::vector<int> tmp;
  std::vector<bool> used(nums.size(), false);

  backtracking(res, tmp, used, nums, 0);

  return res;
}

int main() {
  vector<int> t = {4, 5, 7, 9};
  auto permuted = permute(t);
  return 0;
}