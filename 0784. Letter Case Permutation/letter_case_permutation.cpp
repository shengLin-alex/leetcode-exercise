// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length between 1 and 12.
// S will consist only of letters or digits.

#include <cctype>
#include <deque>
#include <string>
#include <vector>

// 這是一個很簡單但是看起來很醜的bfs
// 而且成績還不錯
// 但正規解法還是推薦使用 stack dfs 或 queue bfs
std::vector<std::string> letterCasePermutation(std::string S) {
  std::vector<std::string> res;
  std::string tmp = "";
  for (const auto &s : S) {
    if (!isdigit(s)) {
      std::string upper_letter = std::string(1, toupper(s)), lower_letter = std::string(1, tolower(s));
      if (res.empty()) {
        res.push_back(tmp + lower_letter);
        res.push_back(tmp + upper_letter);
      } else {
        int idx = res.size() - 1;
        while (idx >= 0) {
          res.push_back(res[idx] + lower_letter);
          res[idx].append(upper_letter);
          idx--;
        }
      }
    } else {
      if (res.empty())
        tmp += s;
      else {
        for (auto &r : res)
          r += s;
      }
    }
  }

  if (res.empty())
    res.push_back(tmp);

  return res;
}

// 解法二 use queue bfs
// std::vector<std::string> letterCasePermutation(std::string S) {
//   if (S.empty())
//     return {};

//   // 為了方便轉換成 vector 所以使用 deque
//   std::deque<std::string> qu{{S}};

//   for (int i = 0; i < S.size(); i++) {
//     if (isdigit(S[i]))
//       continue;

//     int length = qu.size();
//     for (int j = 0; j < length; j++) {
//       auto &cur = qu.front();

//       cur[i] = tolower(cur[i]);
//       qu.push_back(cur);

//       cur[i] = toupper(cur[i]);
//       qu.push_back(cur);

//       qu.pop_front();
//     }
//   }

//   return std::vector<std::string>(qu.begin(), qu.end());
// }

int main() {
  std::string t = "1234bn456";
  auto r = letterCasePermutation(t);

  return 0;
}