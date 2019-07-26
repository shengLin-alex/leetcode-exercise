// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

#include <string>

// A-Z:[65,90] a-Z:[97,122] 0-9:[48,57]
// 解法1: 用 string 暫存 trim 過得 string
bool isPalindrome(std::string s) {
  if (s.empty())
    return true;

  std::string trim = "";
  for (auto c : s) {
    if (48 <= c && c <= 57)
      trim += c;
    if (65 <= c && c <= 90)
      trim += c + 32;
    if (97 <= c && c <= 122)
      trim += c;
  }

  int left = 0, right = trim.size() - 1;

  while (left < right) {
    if (trim[left] == trim[right]) {
      left++;
      right--;
      continue;
    } else {
      return false;
    }
  }

  return true;
}