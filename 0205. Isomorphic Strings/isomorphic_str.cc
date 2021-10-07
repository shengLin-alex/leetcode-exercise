// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
 

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

#include <string>

// 目的是將字母出現次數 mapping 起來
// ex. p a p e r -> t i t l e
// p -> t => 1 -> 1
// a -> i => 2 -> 2
bool isIsomorphic(std::string s, std::string t) {
  int len = s.size();
  int m[256] = { 0 }, n[256] = { 0 }; // ascii 碼 0 ~ 255
  for (int i = 0; i < len; i++) {
    if (m[s[i]] != n[t[i]]) // 位置 mapping 後出現次數不同就 false
      return false;
    m[s[i]] = i + 1; // array 初始皆為 0，此處填值從 1 開始填
    n[t[i]] = i + 1;
  }

  return true;
}

int main(int argc, char **argv) {
  bool res = isIsomorphic("paper", "title");

  return 0;
}