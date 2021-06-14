// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

#include <string>
#include <vector>

// 本題因限定字母出現順序不能打亂
// 因此與 0409. 使用 map 解法不同
// 採用動態規劃搭配 two pointers
// dp[i][i] = 1
//             /  dp[i + 1][j - 1] + 2            if (s[i] == s[j]) // 當左右 pointer 字母一樣時，左右內縮一個字母加 2
// dp[i][j] =
//             \  max(dp[i + 1][j], dp[i][j - 1]) if (s[i] != s[j]) // 當左右 pointer 字母不同時，向右或向左縮一個字母比較找較大之值
int longestPalindromeSubseq(std::string s) {
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    for (int i = n - 1; i >= 0; i--) { // i 由最末端找回前面
      dp[i][i] = 1; // 單一字母為 1

      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1] + 2;
        else
          dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
      }
    }

    return dp[0][n - 1]; // 回傳從頭到最後的該組解
}