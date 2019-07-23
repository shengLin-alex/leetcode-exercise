// Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

// After this process, we have some array B.

// Return the smallest possible difference between the maximum value of B and the minimum value of B.

// Example 1:

// Input: A = [1], K = 0
// Output: 0
// Explanation: B = [1]
// Example 2:

// Input: A = [0,10], K = 2
// Output: 6
// Explanation: B = [2,8]
// Example 3:

// Input: A = [1,3,6], K = 3
// Output: 0
// Explanation: B = [3,3,3] or B = [4,4,4]

// Note:

// 1 <= A.length <= 10000
// 0 <= A[i] <= 10000
// 0 <= K <= 10000

#include <vector>

int smallestRangeI(std::vector<int> &A, int K) {
    int min = A[0];
    int max = A[0];
    int y = 2 * K; // 整個陣列的總和變化為兩倍K

    // 取陣列中最大值與最小值
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > max) {
            max = A[i];
        }

        if (A[i] < min) {
            min = A[i];
        }
    }

    // 最大減去最小還小於兩倍k表示可以調整為 0
    if (max - min < y) {
        return 0;
    } else {
        // 大於2被k則表示可以減去兩倍k
        return max - min - y;
    }
}