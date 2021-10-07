// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
// Example 4:

// Input: pattern = "abba", s = "dog dog dog dog"
// Output: false
 

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lower-case English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <vector>

// 用 istringstream 拆分單字
// 用 two map 對應 pattern 與 單字出現次數
bool wordPattern(std::string pattern, std::string s) {
  std::istringstream in(s);
  std::unordered_map<char, int> p;
  std::unordered_map<std::string, int> w;

  int i = 0, len = pattern.size();
  for (std::string word; in >> word; i++) {
    if (i == len || p[pattern[i]] != w[word]) return false; // i == len 是為了檢查 pattern 已經 match 結束，但 word 還沒結束

    p[pattern[i]] = i + 1; // i + 1 是因為 map value 初始為 0
    w[word] = i + 1;
  }

  return i == len; // 長度不一至就表示 有 pattern 沒 match 完
}

int main() {
  bool res = wordPattern("jquery", "jquery");

  std::cout << res;

  return 0;
}