// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// Example 1:

// Input: [3,0,1]
// Output: 2
// Example 2:

// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space
// complexity?

#include <algorithm>
#include <vector>

// 不用 sort
int missingNumber(std::vector<int> &nums) {
    int n_max = nums.size();
    int sum_num = (n_max + 1) * n_max / 2; // 計算出原本應該要有的總和

    for (int i = 0; i < nums.size(); i++) {
        // 減去現有的數字
        sum_num -= nums[i];
    }

    // 剩下的就是答案
    return sum_num;
}

// int missingNumber(std::vector<int> &nums)
// {
//     std::sort(nums.begin(), nums.end());
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         if (i != nums[i])
//             return i;
//     }
//     return nums[nums.size() - 1] + 1;
// }