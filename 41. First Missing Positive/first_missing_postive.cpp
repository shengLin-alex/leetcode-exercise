// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1

#include <vector>
#include <climits>
#include <cmath>

int firstMissingPostive(std::vector<int>& nums) {
    // first remove all negative and greater than nums.size()
    for (int& n : nums) {
        if (n <= 0 || n > nums.size()) {
            n = INT_MAX;
        }
    }

    for (int& n : nums) {
        int a = abs(n);
        if (a <= nums.size()) { // get valid number 
            if (nums[a - 1] > 0) { // mark if greater then 0
                nums[a - 1] *= -1;
            }
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            return i + 1;
    }

    return nums.size() + 1;
}

int main() {
    std::vector<int> t = {1,3,4,5,6,7,8,10};
    auto r = firstMissingPostive(t);

    return 0;
}