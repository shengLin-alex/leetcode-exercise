// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique
// combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

#include <algorithm>
#include <vector>

// 回朔法
// 遍歷候選數字，求解時都往內push
// 進入遞迴放第二個數字
// 出遞迴的時候 pop 達到回朔
void backtracking(std::vector<std::vector<int>> &res, std::vector<int> &tmp, std::vector<int> &numbers, int sum,
                  int idx) {
    if (sum < 0)
        return; // 爆了 非解

    if (sum == 0) { // 等於0 為一組解
        res.push_back(tmp);
        return;
    }

    for (int i = idx; i < numbers.size(); i++) { // 用for 迴圈的目的就是用來控制下一個填入的數字
        tmp.push_back(numbers[i]);
        backtracking(res, tmp, numbers, sum - numbers[i], i);
        tmp.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;

    backtracking(res, tmp, candidates, target, 0);

    return res;
}

int main() {
    std::vector<int> t = {2, 3, 5};

    auto res = combinationSum(t, 8);

    return 0;
}