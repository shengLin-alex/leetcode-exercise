// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <algorithm>
#include <string>

std::string addStrings(std::string num1, std::string num2) {
  std::string res = "";
  int carry = 0;
  for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--) {
    int a = i >= 0 ? num1[i] - '0' : 0;
    int b = j >= 0 ? num2[j] - '0' : 0;
    res += std::to_string((a + b + carry) % 10);
    carry = (a + b + carry) / 10;
  }

  std::reverse(res.begin(), res.end());

  return res;
}