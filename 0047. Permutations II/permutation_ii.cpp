// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include <vector>
#include <algorithm>

// 類似 0046
// 不同的地方在於這題給的數字會有重複，因此會造成很多組重複出現的解
// 必須進一步判斷
void backtracking(std::vector<std::vector<int>>& res, std::vector<int>& tmp, std::vector<bool>& used, std::vector<int>& nums, int dimension) {
    if (dimension == nums.size()) {
        res.push_back(tmp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
                  /* 前一個數字等於當前要填入的數字 */ /* used[i-1]為 false，表示目前正在處理一組重複出現的解 */
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue; // ex. 1 1 2之所以合法是因為第一個1用過
                                                                       // 但是下一次 1 1 2 的時候第一個1尚未使用 表示是重複處理的解

        used[i] = true;
        tmp.push_back(nums[i]);
        backtracking(res, tmp, used, nums, dimension + 1);
        tmp.pop_back(); // 回朔
        used[i] = false;
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    std::vector<bool> used(nums.size(), false); 
    
    backtracking(res, tmp, used, nums, 0);

    return res;
}

int main() {
    std::vector<int> t = {1,1,2};
    auto r = permuteUnique(t);

    return 0;
}