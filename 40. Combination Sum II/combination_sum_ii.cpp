// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

#include <algorithm>
#include <vector>

void backtracking(std::vector<std::vector<int>>& res, std::vector<int>& tmp, std::vector<int>& candidates, int sum, int idx) {
    if (sum < 0) return;

    if (sum == 0) {
        res.push_back(tmp);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        // 這個判斷式的意義表示說，已經處理過 candidates[idx] 但是發現即將重複處理同樣數字
        if (i > idx && candidates[i] == candidates[i - 1]) {
            continue;
        } // 關鍵，判斷是否重複

        tmp.push_back(candidates[i]);
        backtracking(res, tmp, candidates, sum - candidates[i], i + 1); // i + 1 表示選下一個數字
        tmp.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    std::sort(candidates.begin(), candidates.end()); // 先 sort 來幫助判斷數字是否已經使用

    backtracking(res, tmp, candidates, target, 0);

    return res;
}

int main()
{
    std::vector<int> t = {2,5,2,1,2};
    auto r = combinationSum2(t, 5);

    return 0;
}