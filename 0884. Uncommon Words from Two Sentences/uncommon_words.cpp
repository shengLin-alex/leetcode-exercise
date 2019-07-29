// We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of
// lowercase letters.)

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Return a list of all uncommon words.

// You may return the list in any order.

// Example 1:

// Input: A = "this apple is sweet", B = "this apple is sour"
// Output: ["sweet","sour"]
// Example 2:

// Input: A = "apple apple", B = "banana"
// Output: ["banana"]

// Note:

// 0 <= A.length <= 200
// 0 <= B.length <= 200
// A and B both contain only spaces and lowercase letters.

#include <string>
#include <unordered_map>
#include <vector>

// 簡單粗暴法，建立兩張 hash map 在互相比較取只存在自身map 並且只出現過一次的 word
std::vector<std::string> uncommonFromSentences(std::string A, std::string B) {
  std::vector<std::string> res;
  std::unordered_map<std::string, int> mp1, mp2;
  int j = 0;
  for (int i = 0; i <= A.size(); i++) {
    if (A[i] == ' ' || i == A.size()) {
      mp1[A.substr(j, i - j)]++;
      j = i + 1;
    }
  }

  j = 0;
  for (int i = 0; i <= B.size(); i++) {
    if (B[i] == ' ' || i == B.size()) {
      mp2[B.substr(j, i - j)]++;
      j = i + 1;
    }
  }

  for (auto p : mp1) {
    if (mp2.count(p.first) <= 0 && p.second == 1)
      res.push_back(p.first);
  }

  for (auto p : mp2) {
    if (mp1.count(p.first) <= 0 && p.second == 1)
      res.push_back(p.first);
  }

  return res;
}

// 其實可以把輸入用一個 space 串接起來在建立 hash map
std::vector<std::string> uncommonFromSentences(std::string A, std::string B) {
  std::vector<std::string> res;
  std::unordered_map<std::string, int> mp;
  std::string input = A + " " + B;
  int j = 0;
  for (int i = 0; i <= input.size(); i++) {
    if (input[i] == ' ' || i == input.size()) {
      mp[input.substr(j, i - j)]++;
      j = i + 1;
    }
  }

  for (auto p : mp)
    if (p.second == 1)
      res.push_back(p.first);

  return res;
}

int main() {
  auto r = uncommonFromSentences("s z z z s", "s z ejt");

  return 0;
}