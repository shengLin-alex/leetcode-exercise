// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving
// whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

#include <string>

std::string reverseWords(std::string s) {
  int left = 0;
  for (int i = 0; i <= s.size(); i++) {
    // 遇到 space 或是最後一個單字時進行反轉
    if (i == s.size() || s[i] == ' ') {
      int right = i - 1;
      while (left < right)
        std::swap(s[left++], s[right--]);

      left = i + 1;
    }
  }

  return s;
}