// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum
// equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include <iostream>
#include <unordered_map>
#include <vector>

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
// 根據公式：sum(i, j) = sum(0, j) - sum(0, i)，j > i
// 利用 hash_map，key 為 sum，value 為該 sum 出現過得次數
// 當 sum - k 出現在 hash map 時，表示前面至少出現過 map[sum - k] 次和為 k
int subarraySum(std::vector<int> &nums, int k) {
    int res = 0, sum = 0;
    std::unordered_map<int, int> map{
        {0, 1}}; // 初始化 map[0] = 1，當出現sum - k等於0時，表示出現次數為 1 並且直接累加至 res
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i]; // 累加當前數字
        res += map[sum - k];
        map[sum]++;
    }

    return res;
}

int main() {
    std::vector<int> nums = {1, 2, 1};
    auto r = subarraySum(nums, 3);

    std::cout << r << std::endl;

    return 0;
}