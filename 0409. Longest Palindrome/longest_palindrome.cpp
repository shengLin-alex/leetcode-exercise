// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can
// be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <string>
#include <unordered_map>

// 先統計字母出現次數
// 出現過偶數次全取
// 出現過奇數次取 - 1
// 最後檢查計數與輸入長度是否相同
// 相同直接回傳 不同表示還有字母沒用完可以再 + 1
int longestPalindrome(std::string s) {
  std::unordered_map<char, int> mp;
  for (const auto &c : s)
    mp[c]++;

  int count = 0;
  for (const auto &p : mp) {
    if (p.second > 1 && p.second % 2 == 0)
      count += p.second;

    if (p.second > 1 && p.second % 2 > 0)
      count += p.second - 1;
  }

  if (count == s.size())
    return count;

  return count + 1;
}