// You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

// Example 1:

// Input: "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:

// Input: "AAABBC"
// Output: 188
 

// Note:

// 1 <= tiles.length <= 7
// tiles consists of uppercase English letters.

#include <string>
#include <vector>

// input: AAB
// AAB ABA BAA
// AA  AB  BA
// A   B

// 以上表可知長度 N 的組合結果由 N - 1 結果的再進行剩餘字母分配
// 因此可以利用回朔法 dfs 來將每一層的結果回朔至上一曾
// 將輸入之字串轉為 A-Z 之字母出現次數的統計表
// 在利用回朔進行計算
int backtracking(std::vector<int>& table) {
    int sum = 0;

    for (int i = 0; i < 26; i++) {
        if (table[i] == 0) continue; // 該字母未出現或已經用完跳過

        sum++;
        table[i]--;
        sum += backtracking(table);
        table[i]++; // 回朔
    }

    return sum;
}

int numTilePossibilities(std::string tiles) {
    if (tiles.empty()) return 0;

    std::vector<int> table(26, 0);
    for (auto c : tiles) table[c - 'A']++;

    return backtracking(table);
}

int main() {
    auto t = "AAB";
    auto res = numTilePossibilities(t);

    return 0;
}