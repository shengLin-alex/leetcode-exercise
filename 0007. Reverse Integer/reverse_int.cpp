// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <climits>

int reverse(int x) {
    if (x == INT_MIN) return 0;
    int res = 0;
    bool flag = x < 0;
    x = flag ? -x : x; // 若 x 原本小於 0，則先轉為正

    while (x > 0) {
        // 表示 res * 10 會大於 INT_MAX 避免接下來的運算炸掉所以回傳 0
        if (INT_MAX / 10 < res) return 0;

        // 從個位數開始每次加上目前 x 除以 10的餘數
        // 0 * 10 + (x % 10) -> x / 10 -> res * 10 + (x % 10)
        res = res * 10 + (x % 10);
        x /= 10;
    }

    return flag ? -res : res;
}