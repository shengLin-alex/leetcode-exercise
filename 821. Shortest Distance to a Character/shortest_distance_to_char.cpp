// Given a string S and a character C, return an array of integers representing the shortest distance from the character
// C in the string.

// Example 1:

// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

// Note:

// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.

#include <string>
#include <vector>

// 取每一個字元
// 往右往左看誰先遇到
// std::vector<int> shortestToChar(std::string S, char C) {
//     int len = S.size();
//     std::vector<int> res(len, 0);

//     for (int i = 0; i < len; i++) {
//         int to_right = i, to_left = i;
//         while (to_right < len || to_left >= 0) {
//             if (to_right < len && S[to_right] == C) {
//                 res[i] = to_right - i;
//                 break;
//             }
//             if (to_left >= 0 && S[to_left] == C) {
//                 res[i] = i - to_left;
//                 break;
//             }

//             to_right++;
//             to_left--;
//         }
//     }

//     return res;
// }

// a better approach
// 正反跑兩次
std::vector<int> shortestToChar(std::string S, char C) {
    std::vector<int> res(S.size(), S.size());

    // 從左到右跑一次
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == C)
            res[i] = 0; // 遇到 C 給 0
        else if (i > 0)
            res[i] = res[i - 1] + 1; // 沒遇到 C 且不是第一個數字
                                     // 給前一個位置值+1
    }

    // 從倒數第二個位置往回跑
    for (int i = (int)S.size() - 2; i >= 0; --i) {
        // 每個位置的值為，原本值比較後一個位置值+1(+1是因為後一個位置值為該位置答案，差距位置1所以要+1)取小的
        res[i] = std::min(res[i], res[i + 1] + 1);
    }
    return res;
}

int main() {
    std::string s = "loveleetcode";
    auto r = shortestToChar(s, 'e');

    return 0;
}