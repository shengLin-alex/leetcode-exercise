// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 
//10000100
//1011

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#include <string>

// 難懂版
std::string addBinary(std::string a, std::string b) {
  int i = a.size() - 1, j = b.size() - 1, c = 0;
  std::string res;

  while (i >= 0 || j >= 0 || c == 1) {
    c += i >= 0 ? a[i--] - '0' : 0; // a 當前位數為 0 / 1
    c += j >= 0 ? b[j--] - '0' : 0; // b 當前位數為 0 / 1
    res = char(c % 2 + '0') + res;
    c /= 2;
  }

  return res;
}

// 好懂一點版
std::string addBinary(std::string a, std::string b) {
  int i = a.size() - 1, j = b.size() - 1, c = 0;
  std::string res;

  while (i >= 0 || j >= 0 || c == 1) {
    int p = i >= 0 ? a[i--] - '0' : 0; // a 當前位數為 0 / 1
    int q = j >= 0 ? b[j--] - '0' : 0; // b 當前位數為 0 / 1
    int sum = p + q + c;
    res = std::to_string(sum % 2) + res; // 對 2 取餘數 取得進位完後剩 1 還是 0
    c = sum / 2; // 對 2 取商得到還有沒有進位
  }

  return res;
}