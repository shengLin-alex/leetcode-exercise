// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:

// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

#include <stack>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

// 用 stack 除掉 match 的括號之後利用剩餘的括號位置(index)取得最長的一組合法括號長度
int longestValidParentheses(std::string s) {
    std::stack<std::pair<char, int>> st;
    int s_len = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (!st.empty()) {
            if (st.top().first == '(' && s[i] == ')') {
                st.pop();
                continue;
            }
        }

        st.push({s[i], i});
    }

    int m_len = 0;
    std::vector<int> rest;
    while (!st.empty()) {
        rest.push_back(st.top().second);
        st.pop();
    }

    if (rest.size() == 0) return s.size();

    int last_len = s_len - 1 - rest[0]; // 原始字串多餘的長度到最後面那一個剩餘括號的長度
    int first_len = rest[rest.size() - 1]; // 最前面那一個剩餘括號到0的長度
    for (int i = 1; i < rest.size(); i++) {
        m_len = std::max(m_len, rest[i - 1] - rest[i] - 1);
    }

    return std::max({last_len, first_len, m_len});
}

int main() {
    std::string t = "())(";
    auto r = longestValidParentheses(t);

    return 0;
}