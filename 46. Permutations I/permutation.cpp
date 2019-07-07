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

#include <vector>
#include <iostream>
using namespace std;

void backtracking(std::vector<std::vector<int>>& res, std::vector<int>& tmp, std::vector<bool>& used, std::vector<int>& nums, int dimension) {
    if (dimension == nums.size()) {
        res.push_back(tmp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        tmp.push_back(nums[i]);
        backtracking(res, tmp, used, nums, dimension + 1);
        tmp.pop_back(); // backtrack
        used[i] = false;
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    std::vector<bool> used(nums.size(), false); 
    
    backtracking(res, tmp, used, nums, 0);

    return res;
}

int main()
{
    vector<int> t = {4,5,7,9};
    auto permuted = permute(t);
    return 0;
}