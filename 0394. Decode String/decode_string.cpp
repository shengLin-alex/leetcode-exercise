// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated
// exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those
// repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include <string>

std::string decode(std::string s, int &cursor) {
  std::string res = "";
  int length = s.size();
  while (cursor < length && s[cursor] != ']') {
    if (s[cursor] < '0' || s[cursor] > '9')
      res += s[cursor++]; // 當前字符非數字
    else {
      int count = 0;
      while (s[cursor] >= '0' && s[cursor] <= '9') // 當前字符為數字
        count = count * 10 + s[cursor++] - '0';    // 轉換數字取得次數

      cursor++;                          // 上面迴圈結束後 cursor 會指向 '[' 所以必須跳過
      std::string t = decode(s, cursor); // 由當前 cursor 進入遞迴繼續解碼
      cursor++;                          // 遞迴回傳之後 cursor 會指向 ']' 所以必須跳過
      while (count-- > 0)
        res += t; // 由次數再 append t 至 res
    }
  }

  return res;
}

std::string decodeString(std::string s) {
  int i = 0;
  return decode(s, i);
}

int main() {
  auto r = decodeString("3[a2[c]]");

  return 0;
}