// Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all
// strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4
// times, you need to include that character three times in the final answer.

// You may return the answer in any order.

// Example 1:

// Input: ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: ["cool","lock","cook"]
// Output: ["c","o"]

// Note:

// 1 <= A.length <= 100
// 1 <= A[i].length <= 100
// A[i][j] is a lowercase letter

#include <climits>
#include <string>
#include <vector>

// 利用兩個固定長度(26)陣列來紀錄字母出現次數，一個紀錄每個單字最少出現次數，一個於遍歷 A 時紀錄字母出現次數
std::vector<std::string> commonChars(std::vector<std::string> &A) {
  std::vector<int> count_min(26, INT_MAX); // 用來計數某個單第最少出現次數
  std::vector<std::string> res;

  for (int i = 0; i < A.size(); i++) {
    std::vector<int> count_char(26, 0); // 用來計數當前單字的字母出現次數
    for (auto c : A[i])
      count_char[c - 'a']++;
    for (int j = 0; j < 26; j++) // 比較 count_min 與當前單字字母出現數取較小者
      count_min[j] = std::min(count_min[j], count_char[j]);
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < count_min[i]; j++)
      res.push_back(std::string(1, i + 'a'));
  }

  return res;
}