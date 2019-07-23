// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
// represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For
// each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n
// intervals that CPU are doing different tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish all the given tasks.

// Example:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

// Note:

// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].

#include <algorithm>
#include <vector>

// https://www.cnblogs.com/grandyang/p/7098764.html
int leastInterval(std::vector<char> &tasks, int n) {
    std::vector<int> table(26, 0);
    for (auto c : tasks)
        ++table[c - 'A']; // 計算 task 次數

    std::sort(table.begin(), table.end()); // 排序
    int i = 25, mx = table[25], len = tasks.size();

    while (i >= 0 && table[i] == mx)
        i--; // 取最後模塊分配完之後還剩下的最多次出現的Task的個數

    // mx 最大次數，mx - 1(模塊數)，n + 1(每個模塊個數)
    // 避免模塊長度小於原始長(比如 n = 0 的情況)，最終答案必定不得小於原始長度
    return std::max(len, (mx - 1) * (n + 1) + 25 - i);
}