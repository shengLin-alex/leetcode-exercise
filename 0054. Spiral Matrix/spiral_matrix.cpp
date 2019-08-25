// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <vector>

// 螺旋 => 需要四條邊的起點 up down left right
// 在每次循環中更新四個起點來遍歷螺旋
std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty())
    return {};

  int m = matrix.size(), n = matrix[0].size();
  int up = 0, down = m - 1, left = 0, right = n - 1;
  std::vector<int> res;

  // 檢查 res 長度，尚未遍歷完所有數字則繼續
  // 由範例 2 來看
  // 遍歷的順序為 → ↓ ← ↑
  // 其中引號內的為起點(由於左上角同時為 up 與 left 因此用雙引號)
  // "→" → → '→'
  //  ↑       ↓
  //  ↑       ↓
  // '←' ← ←  ←
  // 完成一圈之後起點往內縮
  while (res.size() < m * n) {
    for (int i = left; i <= right && res.size() < m * n; i++) {
      res.push_back(matrix[up][i]); // i 從 left 開始遍歷 up 邊，直到 right
    }

    for (int i = up + 1; i <= down - 1 && res.size() < m * n; i++) {
      res.push_back(matrix[i][right]); // i 從 up + 1 開始遍歷 right 邊，直到 down - 1
    }

    for (int i = right; i >= left && res.size() < m * n; i--) {
      res.push_back(matrix[down][i]); // i 從 right 開始往回遍歷 down 邊，直到 left
    }

    for (int i = down - 1; i >= up + 1 && res.size() < m * n; i--) {
      res.push_back(matrix[i][left]); // i 從 down - 1 開始往上遍歷 left 邊，直到 up + 1
    }

    up++;
    down--;
    left++;
    right--;
  }

  return res;
}