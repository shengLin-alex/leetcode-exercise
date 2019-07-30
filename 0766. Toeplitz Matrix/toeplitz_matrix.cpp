// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

// Example 1:

// Input:
// matrix = [
//   [1,2,3,4],
//   [5,1,2,3],
//   [9,5,1,2]
// ]
// Output: True
// Explanation:
// In the above grid, the diagonals are:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
// In each diagonal all elements are the same, so the answer is True.
// Example 2:

// Input:
// matrix = [
//   [1,2],
//   [2,2]
// ]
// Output: False
// Explanation:
// The diagonal "[1, 2]" has different elements.

// Note:

// matrix will be a 2D array of integers.
// matrix will have a number of rows and columns in range [1, 20].
// matrix[i][j] will be integers in range [0, 99].

// Follow up:

// What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the
// matrix into the memory at once? What if the matrix is so large that you can only load up a partial row into the
// memory at once?

#include <vector>

bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty())
    return false;

  int m = matrix.size(), n = matrix[0].size();
  if (m == 1 || n == 1) // 只有一行或一列就是 true
    return true;

  // 對行遍歷
  // 注意 i < m - 1，m - 1是因為最後一個行的數字以對角線來看肯定只有一個數字可以跳過
  for (int i = 0; i < m - 1; i++) {
    // 檢查位於自己右下的數字是否跟自己一樣
    int x = 0, y = i, comp = matrix[y][x];
    while (x < n && y < m) {
      if (matrix[y++][x++] != comp)
        return false;
    }
  }

  // 對列遍歷並且跳過第一行(已經於上面處理過)
  for (int j = 1; j < n - 1; j++) {
    int x = j, y = 0, comp = matrix[y][x];
    while (x < n && y < m) {
      if (matrix[y++][x++] != comp)
        return false;
    }
  }

  return true;
}

// 上面的 code 可以改成用巣狀 for loop
// 效能上跟上面差不多但是簡潔許多
bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty())
    return false;

  int m = matrix.size(), n = matrix[0].size();
  if (m == 1 || n == 1)
    return true;

  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (matrix[i][j] != matrix[i + 1][j + 1])
        return false;
    }
  }

  return true;
}