// A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses
// strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid
// parentheses strings.

// A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B,
// with A and B nonempty valid parentheses strings.

// Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are
// primitive valid parentheses strings.

// Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.

// Example 1:

// Input: "(()())(())"
// Output: "()()()"
// Explanation:
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
// Example 2:

// Input: "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation:
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
// Example 3:

// Input: "()()"
// Output: ""
// Explanation:
// The input string is "()()", with primitive decomposition "()" + "()".
// After removing outer parentheses of each part, this is "" + "" = "".

// Note:

// S.length <= 10000
// S[i] is "(" or ")"
// S is a valid parentheses string

#include <string>

std::string removeOuterParentheses(std::string S) {
    int st = 0, idx = 0, count = 0;
    std::string res = "";

    while (idx < S.size()) {
        if (S[idx] == '(')
            count++;
        if (S[idx] == ')')
            count--;

        // valid 的時候表示
        // st為最外圍開括號的位置
        // idx為最外圍閉括號的位置
        // 取 substr
        if (count == 0) {
            res += S.substr(st + 1, idx - st - 1);
            st = idx + 1;
        }

        idx++;
    }

    return res;
}

int main() {
    std::string t = "(()())(())";

    auto res = removeOuterParentheses(t);

    return 0;
}