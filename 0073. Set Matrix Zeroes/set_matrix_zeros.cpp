// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Example 1:

// Input:
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output:
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:

// Input:
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output:
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include <vector>

// 題目最終要求為 O(1) space
// 因此提昇了不少難度
// O(mn) 很簡單直接再生成一個 matrix，接著掃描原 matrix 來填值即可
// O(m + n) 則是利用兩個陣列長度 m n 紀錄哪個 row 或 col 有 0
// in-place 的方式則是利用 第一行與第一列來當作 flags
// 詳情如下
void setZeroes(std::vector<std::vector<int>> &matrix) {
  bool hasFirstColZero = false; // flag for check first col has zero or not
  bool hasFirstRowZero = false; // flag for check first row has zero or not
  int m = matrix.size(), n = matrix[0].size();

  for (int i = 0; i < m; i++) { // for check first col has zero
    if (matrix[i][0] == 0) {
      hasFirstColZero = true;
      break;
    }
  }

  for (int i = 0; i < n; i++) { // for check first raw has zero
    if (matrix[0][i] == 0) {
      hasFirstRowZero = true;
      break;
    }
  }

  for (int i = 1; i < m; i++) { // use first col and first row as flags
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (int i = 1; i < m; i++) { // set zero except first row and first col
    for (int j = 1; j < n; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
        matrix[i][j] = 0;
    }
  }

  if (hasFirstColZero) { // handle first col
    for (int i = 0; i < m; i++)
      matrix[i][0] = 0;
  }

  if (hasFirstRowZero) { // handle first row
    for (int i = 0; i < n; i++)
      matrix[0][i] = 0;
  }
}