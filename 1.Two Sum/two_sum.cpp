#include <vector>
#include <unordered_map>

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    int len = nums.size();

    std::unordered_map<int, int> map;
    for (int i = 0; i < len; i++)
    {
        int ans = target - nums[i];
        if (map.count(nums[i]) > 0)
        { // has key
            return std::vector<int>{map[nums[i]], i};
        }
        map[ans] = i;
    }

    return std::vector<int>{};
}