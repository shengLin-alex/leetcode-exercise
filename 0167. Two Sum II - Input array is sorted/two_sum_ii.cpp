// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a
// specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must
// be less than index2.

// Note:

// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.
// Example:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

#include <unordered_map>
#include <vector>

// 直接用 0001 的解法就好
std::vector<int> twoSum(std::vector<int> &numbers, int target) {
  int len = numbers.size();
  std::unordered_map<int, int> map;

  for (int i = 0; i < len; i++) {
    int ans = target - numbers[i];
    if (map.count(numbers[i]) > 0)
      return {map[numbers[i]], i + 1};
    else {
      map[ans] = i + 1;
    }
  }
}