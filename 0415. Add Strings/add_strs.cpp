// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <algorithm>
#include <string>

// 按照正常的方式來進行加法即可
std::string addStrings(std::string num1, std::string num2) {
  std::string res = "";
  int carry = 0;
  // 將條件與疊代用 for loop 一次搞定，碉堡
  for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--) {
    int a = i >= 0 ? num1[i] - '0' : 0;
    int b = j >= 0 ? num2[j] - '0' : 0;
    res += std::to_string((a + b + carry) % 10); // 取餘數為和
    carry = (a + b + carry) / 10;                // 取商為進位
  }

  // 由於每次結果是 append 到 res 後面，因此需反轉
  std::reverse(res.begin(), res.end());
  return res;
}