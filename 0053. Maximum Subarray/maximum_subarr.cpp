// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum
// and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which
// is more subtle.

#include <climits>
#include <vector>

using namespace std;

// 本題動態規劃的關鍵 : nums[i] = max(nums[i - 1] + nums[i], nums[i])
// nums[i]表示第i個元素能取到的最大值
int maxSubArray(vector<int> &nums) {
    int res = INT_MIN, sum = 0;

    for (auto n : nums) {
        sum = n + (sum > 0 ? sum : 0);
        res = max(res, sum);
    }

    return res;
}