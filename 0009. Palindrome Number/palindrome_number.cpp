// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

// Example 1:

// Input: x = 121
// Output: true
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Example 4:

// Input: x = -101
// Output: false

// 假設 x = 1551
// 首先對 x 除以 1000 可得到千位數
// 再對 x % 10 可以取個位數
// 後續再取中間 55 出來比較
bool isPalindrome(int x) {
  if (x < 0)
    return false;

  int div = 1;
  // 設定 div 位數需等於 x 位數
  while (x / div >= 10)
    div *= 10;

  while (x > 0) {
    int left = x / div; // 取得當前最高位數之數字
    int right = x % 10; // 取得當前個位數
    if (left != right)
      return false;

    // 取出中間
    x = (x % div) / 10;

    // 整串數字少了兩位數 所以 div 除以 100
    div /= 100;
  }

  return true;
}