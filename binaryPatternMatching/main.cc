#include <string>
#include <vector>

bool isVowels(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int binaryPatternMatching(std::string pattern, std::string s) {
  int res = 0;
  int len = s.size() - pattern.size();

  for (int i = 0; i <= len; i++) {
    int j = 0;
    for (j = 0; j < pattern.size(); j++) {
      if (pattern[j] == '0' && isVowels(s[i + j]))
        continue;
      else if (pattern[j] == '1' && !isVowels(s[i + j]))
        continue;
      else
        break;
    }

    if (j == pattern.size())
      res++;
  }

  return res;
}

int wordCount(std::vector<std::vector<char>> board, std::string word) {
  
}

int main() {
  int res = binaryPatternMatching("010", "amazing");

  return 0;
}