// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

#include <string>

bool isPalindrome(std::string s) {
  if (s.empty())
    return true;

  int left = 0, right = s.size() - 1;
  while (left < right) {
    if (s[left] < 48 || s[left] > 57 && s[left] < 65 || s[left] < 97 && s[left] > 90 || s[left] > 122) {
      left++;
      continue;
    }

    if (s[right] < 48 || s[right] > 57 && s[right] < 65 || s[right] < 97 && s[right] > 90 || s[right] > 122) {
      right--;
      continue;
    }

    char l = 65 <= s[left] && s[left] <= 90 ? s[left] + 32 : s[left];
    char r = 65 <= s[right] && s[right] <= 90 ? s[right] + 32 : s[right];
    
    if (l == r) {
      left++;
      right--;
      continue;
    } else {
      return false;
    }
  }

  return true;
}

// A-Z:[65,90] a-Z:[97,122] 0-9:[48,57]
// 解法1: 用 string 暫存 trim 過得 string
// bool isPalindrome(std::string s) {
//   if (s.empty())
//     return true;

//   std::string trim = "";
//   for (auto c : s) {
//     if (48 <= c && c <= 57)
//       trim += c;
//     if (65 <= c && c <= 90)
//       trim += c + 32;
//     if (97 <= c && c <= 122)
//       trim += c;
//   }

//   int left = 0, right = trim.size() - 1;

//   while (left < right) {
//     if (trim[left] == trim[right]) {
//       left++;
//       right--;
//       continue;
//     } else {
//       return false;
//     }
//   }

//   return true;
// }

int main() {
  std::string str = "A man, a plan, a canal: Panama";
  auto res = isPalindrome(str);

  return 0;
}