// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
// stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last
// one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two
// adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
// money you can rob tonight without alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

#include <vector>

using namespace std;

int rob(vector<int> &nums) {
    // 搶第一家就不能搶最後一家 => max(不搶第一家的max, 不搶最後一家的max)
    int len = nums.size();
    if (len <= 1)
        return nums.empty() ? 0 : nums[0];

    return max(rob(nums, 1, len), rob(nums, 0, len - 1));
}

int rob(vector<int> &nums, int left, int right) {
    if (right - left <= 1)
        return nums[left]; // right - left 至少差距 2才能動態規劃

    vector<int> dp(right, 0);
    dp[left] = nums[left];
    dp[left + 1] = max(nums[left], nums[left + 1]);

    for (int i = left + 2; i < right; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp.back();
}