// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could
// represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any
// letters.

// http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <string>
#include <vector>

void backtracking(std::string &digits, std::vector<std::string> &dict, std::vector<std::string> &sol, std::string &res,
                  int level) {
  if (res.size() > 0 && res.size() == digits.size()) { // 當 res 長度與 digits 長度一樣時表示為一組解
    sol.push_back(res);
    return;
  }

  std::string letter = dict[digits[level] - '0']; // 從第 1 個 letters 開始取，進入遞迴取下一個
  for (int i = 0; i < letter.size(); i++) { // 每次進入遞迴都從 0 跑迴圈因為要從第一個 letter 塞入
    res.push_back(letter[i]);
    backtracking(digits, dict, sol, res, level + 1);
    res.pop_back(); // backtrack
  }
}

// 和 combination系列還有 permutation系列都是相同的思路
std::vector<std::string> letterCombinations(std::string digits) {
  if (digits.empty())
    return {};

  std::vector<std::string> sol;
  std::string res;
  std::vector<std::string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  backtracking(digits, dict, sol, res, 0);

  return sol;
}

int main() {
  auto r = letterCombinations("23");

  return 0;
}