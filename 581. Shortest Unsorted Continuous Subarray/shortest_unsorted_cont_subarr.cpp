// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending
// order, then the whole array will be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.

#include <algorithm>
#include <vector>

// 利用 copy arry
int findUnsortedSubarray(std::vector<int> &nums) {
    std::vector<int> copy(nums);
    std::sort(copy.begin(), copy.end());

    int left = 0, right = nums.size() - 1;
    while (left < nums.size()) {
        if (nums[left] != copy[left])
            break;
        left++;
    }
    while (right >= 0) {
        if (nums[right] != copy[right])
            break;
        right--;
    }

    return left < right ? right - left + 1 : 0;
}

// 利用 two pointer 找左右區間最大值，並檢查當前數字是不是該最大值
// 很慢，但是不用額外記憶體
int findUnsortedSubarray(std::vector<int> &nums) {
    if (nums.size() < 2)
        return 0;

    int left = 0, right = nums.size() - 1;

    while (left < nums.size()) {
        int min = *std::min_element(nums.begin() + left, nums.end());
        if (nums[left] != min)
            break;

        left++;
    }

    while (right >= 0) {
        int max = *std::max_element(nums.begin(), nums.begin() + right + 1);
        if (nums[right] != max)
            break;

        right--;
    }

    return left < right ? right - left + 1 : 0;
}