// Given an integer n, return the number of trailing zeroes in n!.

// Example 1:

// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Note: Your solution should be in logarithmic time complexity.

int trailingZeroes(int n) {
  // 題目意思即等於找到 n 階乘中乘數 為 10, 10 = 2 x 5, 2會出現比5多
  // 所以等於找 5的個數
  return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}