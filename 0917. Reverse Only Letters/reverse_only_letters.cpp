// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and
// all letters reverse their positions.

// Example 1:

// Input: "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"

// Note:

// S.length <= 100
// 33 <= S[i].ASCIIcode <= 122
// S doesn't contain \ or "

#include <string>

// A-Z 65~90; a-z 97~122;
std::string reverseOnlyLetters(std::string S) {
    int left = 0, right = S.size() - 1;

    while (left < right) {
        bool check_left = 65 <= S[left] && S[left] <= 90 || 97 <= S[left] && S[left] <= 122;
        bool check_right = 65 <= S[right] && S[right] <= 90 || 97 <= S[right] && S[right] <= 122;
        if (check_left && check_right) {
            std::swap(S[left++], S[right--]);
        }

        if (!check_left)
            left++;
        if (!check_right)
            right--;
    }

    return S;
}