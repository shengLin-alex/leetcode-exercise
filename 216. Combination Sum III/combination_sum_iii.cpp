// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be
// used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

#include <vector>

void backtracking(std::vector<std::vector<int>> &res, std::vector<int> &sol, std::vector<int> &nums,
                  std::vector<bool> &used, int sum, int k, int idx) {
    if (sum < 0)
        return;

    if (sol.size() == k && sum == 0) {
        res.push_back(sol);
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        if (!used[i]) { // 使用過不能再用
            used[i] = true;
            sol.push_back(nums[i]);
            backtracking(res, sol, nums, used, sum - nums[i], k, i);
            sol.pop_back(); // 回朔
            used[i] = false;
        }
    }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<int> nums(9);
    for (int i = 1; i <= 9; i++)
        nums[i - 1] = i;

    std::vector<std::vector<int>> res;
    std::vector<int> sol;
    std::vector<bool> used(9, false);

    backtracking(res, sol, nums, used, n, k, 0);

    return res;
}

int main() {
    auto r = combinationSum3(3, 9);

    return 0;
}