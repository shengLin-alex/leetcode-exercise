// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be
// segmented into a space-separated sequence of one or more dictionary words.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:

// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifndef 窮舉會失敗

// 利用窮舉，會被 oj reject
void helper(bool &res, std::string &sol, std::unordered_map<std::string, bool> &sol_mp, std::string &s,
            std::vector<std::string> &wordDict) {
  if (sol_mp.count(sol) > 0) {
    res = sol_mp[sol];
    return;
  }

  if (!sol.empty() && sol != s.substr(0, sol.length())) {
    sol_mp[sol] = false;
    return;
  }

  if (sol.length() > s.length()) {
    sol_mp[sol] = false;
    return;
  }

  if (s.length() == sol.length() && s == sol) {
    res = true;
    return;
  }

  for (int i = 0; i < wordDict.size(); i++) {
    sol += wordDict[i];
    helper(res, sol, sol_mp, s, wordDict);

    if (res)
      break;

    sol.erase(sol.rfind(wordDict[i]), wordDict[i].length());
  }
}

// 非解法，窮舉花太多時間 oj 會拒絕
bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
  bool res = false;
  std::string sol = "";
  std::unordered_map<std::string, bool> sol_mp;
  helper(res, sol, sol_mp, s, wordDict);

  return res;
}

#endif

#ifndef SOL1

bool check(std::string &s, std::unordered_set<std::string> set, int start, std::vector<int> &mem) {
  if (start >= s.size()) // cursor 大於等於欲檢查字符串時表示已經檢查結束且符合題意
    return true;

  if (mem[start] != -1) // mem 紀錄過某一位置先前計算結果
    return mem[start];

  for (int i = start + 1; i <= s.size(); i++) {
    auto sub = s.substr(start, i - start);
    if (set.count(sub) && check(s, set, i, mem)) {
      return mem[start] = 1;
    }
  }

  return mem[start] = 0;
}

// 解法1 利用字段切割與 hash set 跑遞迴(dfs)檢查是否出現過該字段
bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
  std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
  std::vector<int> mem(s.size(), -1);

  auto r = check(s, set, 0, mem);

  return r;
}

#endif

#ifndef SOL2

// 解法2 神奇的動態規劃
// dp[i] 為 [0,i) 是否可以拆分
bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
  std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
  std::vector<bool> dp(s.size() + 1, false); // s.size() + 1 for hand empty string
  dp[0] = true;                              // empty string

  for (int i = 0; i < dp.size(); i++) {
    for (int j = 0; j < i; j++) {
      // 將字段拆解為:
      // [0, j) => dp[j]
      // [j, i) => s.substr(j, i - j)
      // 當兩段同時 true 時表是 [0, i) 為 true
      if (dp[j] && set.count(s.substr(j, i - j))) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp.back();
}

#endif

#ifndef SOL3

// 解法3 神奇的 bfs
bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
  std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
  std::vector<bool> visited(s.size(), false);
  std::queue<int> qu{{0}};

  while (!qu.empty()) {
    int start = qu.front();
    qu.pop();

    if (visited[start])
      continue;

    for (int i = start + 1; i <= s.size(); i++) {
      if (set.count(s.substr(start, i - start))) {
        qu.push(i);
        if (i == s.size())
          return true;
      }
    }

    visited[start] = true;
  }

  return false;
}

#endif

int main() {
  std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  std::vector<std::string> d = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                                "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

  auto r = wordBreak(s, d);

  return 0;
}