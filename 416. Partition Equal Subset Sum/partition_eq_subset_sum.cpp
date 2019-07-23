// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such
// that the sum of elements in both subsets is equal.

// Note:

// Each of the array element will not exceed 100.
// The array size will not exceed 200.

// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

#include <vector>

using namespace std;

// 類似 494. Target Sum

// group A & group B
// sum(A) = sum(B)
// sum(A) + sum(B) = sum(nums)
// => sum(A) = sum(nums) / 2
// 題目變成：給一數組nums 求和為 sum(nums) / 2是否有解
bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto n : nums) {
        sum += n;
    }

    if (sum % 2 != 0)
        return false;

    int S = sum / 2;
    vector<bool> dp(S + 1, false);
    dp[0] = true;
    for (int n : nums)
        for (int i = S; i >= n; i--)
            dp[i] = dp[i] || dp[i - n];

    return dp[S];
}