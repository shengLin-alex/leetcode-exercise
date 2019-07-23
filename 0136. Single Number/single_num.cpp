// Given a non-empty array of integers, every element appears twice except for one. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:

// Input: [2,2,1]
// Output: 1
// Example 2:

// Input: [4,1,2,1,2]
// Output: 4

#include <vector>

int singleNumber(std::vector<int> &nums) {
    int left = 0;

    for (auto n : nums) {
        // XOR 相同為 0 不同為 1
        left ^= n;
    }

    return left;
}