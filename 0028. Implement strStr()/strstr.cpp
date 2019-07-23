// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr()
// and Java's indexOf().

#include <string>

int strStr(std::string haystack, std::string needle) {
    if (needle.empty())
        return 0;

    int m = haystack.size(), n = needle.size();
    if (n > m)
        return -1;

    // 由於已知 needle 必定小於 haystack，因此外層迴圈我們只需要檢查至 m - n
    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }

        // j 等於 needle 長度表示為答案，回傳 haystack 當前比對之 index
        if (j == n)
            return i;
    }

    return -1;
}

int main() {
    auto r = strStr("mississippi", "issip");

    return 0;
}