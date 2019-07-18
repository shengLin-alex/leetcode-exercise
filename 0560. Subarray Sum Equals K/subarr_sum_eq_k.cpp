// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include <vector>
#include <unordered_map>
#include <iostream>

// 暴力法
// int subarraySum(std::vector<int>& nums, int k) {
//     int res = 0, len = nums.size();

//     for (int i = 0; i < len; i++) {
//         int sum = nums[i];
//         if (sum == k) res++;
//         for (int j = i + 1; j < len; j++) {
//             sum += nums[j];
//             if (sum == k) res++;
//         }
//     }

//     return res;
// }

// hash map 查找法
int subarraySum(std::vector<int>& nums, int k) {
    int res = 0, sum = 0;
    std::unordered_map<int, int> map{{0,1}};
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        res += map[sum - k];
        map[sum]++;
    }

    return res;
}

int main() {
    std::vector<int> nums = {-10,2,3,-3,4,-4,2,-2};
    auto r = subarraySum(nums, 0);

    std::cout << r << std::endl;

    return 0;
}