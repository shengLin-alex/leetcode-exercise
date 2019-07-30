// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some
// characters of the given string. If there are more than one possible results, return the longest word with the
// smallest lexicographical order. If there is no possible result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]

// Output:
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]

// Output:
// "a"
// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.

#include <algorithm>
#include <string>
#include <vector>

std::string findLongestWord(std::string s, std::vector<std::string> &d) {
  // 先對 dict 重新排序
  std::sort(d.begin(), d.end(), [](std::string a, std::string b) {
    if (a.size() == b.size()) // 長度相同則比較子母小的在前面
      return a < b;

    return a.size() > b.size(); // 長度較長的在前面
  });

  // 遍歷 dict
  // 並遍歷 s 檢查每一字符
  // 利用 cursor 當 cursor 位置小於目標字符串 (str) 時，自增 1
  // 由於先前已經排序過 dict 的長度與 lexicographical order 因此完成 s 字符檢查後
  // cursor 若等於 str 的長度，即為最長可由刪除字符取得之字符串
  for (auto str : d) {
    int cursor = 0;
    for (auto c : s) {
      if (cursor < str.size() && str[cursor] == c)
        cursor++;
    }

    if (cursor == str.size())
      return str;
  }

  return "";
}