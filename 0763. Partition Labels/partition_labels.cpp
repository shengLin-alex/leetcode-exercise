// A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that
// each letter appears in at most one part, and return a list of integers representing the size of these parts.

// Example 1:
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
// Note:

// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> partitionLabels(std::string S) {
    std::vector<int> res;
    std::unordered_map<char, int> map;

    // 紀錄每一個出現的字母最後出現的位置
    for (int i = 0; i < S.size(); i++)
        map[S[i]] = i;

    // 轉換後的結果為：
    // a -> 8
    // b -> 5
    // c -> 7
    // d -> 14
    // e -> 15
    // f -> 11
    // g -> 13
    // h -> 19
    // i -> 22
    // j -> 23
    // k -> 20
    // l -> 21

    int start = 0, last = 0;
    for (int i = 0; i < S.size(); i++) {
        // 在 i 追上 last 之前持續更新 last 最長的長度
        last = std::max(last, map[S[i]]);
        if (i == last) { // i 追上 last，此時的i即為 partition 的最後位置
            res.push_back(i - start + 1);
            start = i + 1; // 將 start 更新為下一個位置
        }
    }

    return res;
}