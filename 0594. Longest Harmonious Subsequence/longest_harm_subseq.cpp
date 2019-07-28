// We define a harmounious array as an array where the difference between its maximum value and its minimum value is
// exactly 1.

// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible
// subsequences.

// Example 1:

// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

#include <unordered_map>
#include <vector>

int findLHS(std::vector<int> &nums) {
  std::unordered_map<int, int> mp;

  // 先統計所有數字出現次數
  for (auto n : nums)
    mp[n]++;

  int count = 0;

  // 接著遍歷 map，檢查前後相差 1 的兩個 key 取得總和並取最大值
  for (const auto &p : mp) {
    // 檢查目前 map 是否存過當前 key - 1 的數字
    if (mp.count(p.first - 1))
      count = std::max(mp[p.first - 1] + p.second, count);

    // 同理，檢查 key + 1
    if (mp.count(p.first + 1))
      count = std::max(mp[p.first + 1] + p.second, count);
  }

  return count;
}