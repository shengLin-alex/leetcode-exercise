#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

bool map_contains_key(std::unordered_map<char, bool> map, char key) {
    if (map.find(key) == map.end())
        return false;
    return true;
}

// 關鍵：利用 two pointers 來維護的滑動視窗
int lengthOfLongestSubstring(string s) {
    unordered_map<char, bool> map;
    // 移動視窗 rp代表視窗右邊 lp左邊
    // 盡可能的擴大視窗範圍
    int rp = 0, lp = 0, ans = 0;
    while (rp < s.size() && lp < s.size()) {
        if (!map_contains_key(map, s[rp])) {
            map.insert({s[rp], true});
            ++rp;
            ans = max(ans, rp - lp);
        } else {
            map.erase(s[lp]); // 殺到前一次出現的char，包含該字符殺到不見為止
            ++lp;
        }
    }

    return ans;
}

int main() {
    string t = "sumvqwpnvrodonsmumpmazodwlwuxknpezmxxeksvyymlqyheptepjilxeiurxlvzasweerbcpnphnzmdssueahbhpvyni";
    int r = lengthOfLongestSubstring(t);
    cout << r << endl;
    return 0;
}