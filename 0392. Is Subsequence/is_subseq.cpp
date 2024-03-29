// Given a string s and a string t, check if s is subsequence of t.

// You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~=
// 500,000) string, and s is a short string (<=100).

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of
// the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of
// "abcde" while "aec" is not).

// Example 1:
// s = "abc", t = "ahbgdc"

// Return true.

// Example 2:
// s = "axc", t = "ahbgdc"

// Return false.

// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has
// its subsequence. In this scenario, how would you change your code?

// Credits:
// Special thanks to @pbrother for adding this problem and creating all test cases.

#include <string>

// 利用 two pointer
// s[i] == t[j] 時 i 自增 1 當遍歷結束 i == s.size() 時表示 s 的所有字符皆出現過
bool isSubsequence(std::string s, std::string t) {
  int i = 0, j = 0;
  while (j < t.size() && i < s.size()) {
    if (s[i] == t[j])
      i++;

    j++;
  }

  if (i == s.size())
    return true;

  return false;
}

int main() {
  std::string s = "abc";
  std::string t = "ahbgdc";

  auto r = isSubsequence(s, t);

  return 0;
}