// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
// parentheses substring.

// Example 1:

// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:

// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

#include <algorithm>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// 官方有指出這題可以用動態規劃，以下是我個人用 stack的解法
// O(n) time, O(n) space
// Runtime: 8 ms, faster than 73.47% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 10.4 MB, less than 5.93% of C++ online submissions for Longest Valid Parentheses.
// 由於使用大量容器輔助所以記憶體評估很差XD

// 利用 stack 除掉 match 的括號之後利用剩餘的括號位置(index)取得最長的一組合法括號長度
// 有點類似 0020 Valid Parentheses的想法
int longestValidParentheses(std::string s) {
    std::stack<std::pair<char, int>> st;
    int s_len = s.size();

    // 在這個 for 迴圈處理掉所有 valid 的括號組合
    // 最後剩下來的就會是一個 ('非法括號字符','與其位置')的 value pair
    for (int i = 0; i < s.size(); i++) {
        if (!st.empty()) {
            if (st.top().first == '(' && s[i] == ')') {
                st.pop();
                continue;
            }
        }

        st.push({s[i], i});
    }

    // 將 pair的位置資料轉入陣列
    int m_len = 0;
    std::vector<int> rest;
    while (!st.empty()) {
        rest.push_back(st.top().second);
        st.pop();
    }

    if (rest.size() == 0)
        return s.size();

    // 示意：  o o x o o x o o o x
    // index: 0 1 2 3 4 5 6 7 8 9
    int last_len = s_len - 1 - rest[0];    // 原始字串多餘的長度到最後面那一個剩餘括號的長度
    int first_len = rest[rest.size() - 1]; // 最前面那一個剩餘括號到0的長度

    // 其餘的長度互相比較
    for (int i = 1; i < rest.size(); i++) {
        m_len = std::max(m_len, rest[i - 1] - rest[i] - 1);
    }

    // 最後取三段長度最長的
    return std::max({last_len, first_len, m_len});
}

int main() {
    std::string t = "())(";
    auto r = longestValidParentheses(t);

    return 0;
}