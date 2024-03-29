// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
// valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

// 利用 stack 的特性 LIFO 後進先出
// 將開括號放進 stack 遇到閉括號就 pop
// 最後檢查 stack 是否是空的
bool isValid(std::string s) {
  if (s.empty())
    return true;

  std::unordered_map<char, char> map;
  map['{'] = '}';
  map['['] = ']';
  map['('] = ')';

  std::stack<char> st;
  for (auto c : s) {
    if (map.count(c) > 0) { // 只允許開括號放進 stack
      st.push(c);
      continue;
    }

    if (!st.empty() && c == map[st.top()]) {
      st.pop();
      continue;
    } else {
      return false;
    }
  }

  return st.empty();
}

int main(int argc, char **argv) {
  std::string t = std::string(argv[1]);
  bool res = isValid(t);

  std::cout << res << std::endl;

  return 0;
}