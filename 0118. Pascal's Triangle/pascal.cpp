// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res(numRows);
    if (numRows == 0)
        return res;

    for (int i = 0; i < numRows; i++) {
        if (i == 0)
            res[i] = {1};
        if (i == 1)
            res[i] = {1, 1};
        if (i > 1) {
            std::vector<int> r;
            for (int j = 0; j < i + 1; j++) {
                // 根據帕斯卡三角形每一層第一個數字與最後一個數字皆為 1
                if (j == 0 || j == i) {
                    r.push_back(1);
                    continue;
                }

                // 其餘數字為上一層同一個 index 加上 前一個 index 之數字
                r.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }

            res[i] = r;
        }
    }

    return res;
}

int main(int argc, char **argv) {
    auto res = generate(2);
    return 0;
}