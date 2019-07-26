// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array
// contain a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Example 2:

// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.

#include <vector>

using namespace std;

// 沒什麼特別屌的算法
// 借助 carry 來幫助計算
vector<int> plusOne(vector<int> &digits) {
  int len = digits.size();
  int carry = digits[len - 1] == 9 ? 1 : 0;
  digits[len - 1] = digits[len - 1] == 9 ? 0 : digits[len - 1] + 1;

  for (int i = len - 2; i >= 0; i--) {
    // 最一開始就需要進位計算才需要進入
    if (carry > 0) {
      // 遇到 9，+ 1 之後變成 10
      // 原本位置更新為 0
      // carry 設為 1
      if (digits[i] == 9) {
        digits[i] = 0;
        carry = 1;
        continue;
      } else {
        digits[i]++;
        break;
      }
    }

    break;
  }

  // 最後進位 0xxxx
  // 必須在最前面在插入 1
  // ex 9999 -> 0000 -> 10000
  if (digits[0] == 0) {
    digits.insert(digits.begin(), 1);
  }

  return digits;
}