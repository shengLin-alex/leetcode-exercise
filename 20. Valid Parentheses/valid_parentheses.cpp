// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

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
#include <unordered_map>
#include <string>

using namespace std;

bool map_contains_key(std::unordered_map<char, char>& map, char key) {
    if (map.find(key) == map.end()) return false;
    return true;
}

bool isValid(string s) {
    if (s.empty()) return true;

    unordered_map<char, char> map;
    map['{'] = '}';
    map['['] = ']';
    map['('] = ')';

    stack<char> st;
    for (auto c : s) {
        if (map_contains_key(map, c)) {
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

int main(int argc, char** argv) {
    string t = string(argv[1]);
    bool res = isValid(t);

    cout << res << endl;

    return 0;
}