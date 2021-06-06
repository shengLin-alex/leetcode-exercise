// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra
// space.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]

#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums) {
  vector<bool> t(nums.size(), false);
  vector<int> res;
  for (auto n : nums) {
    // 紀錄出現的數字
    t[n - 1] = true;
  }

  for (int i = 0; i < nums.size(); i++) {
    // 找出沒出現的數字
    if (!t[i]) {
      res.push_back(i + 1);
    }
  }

  return res;
}