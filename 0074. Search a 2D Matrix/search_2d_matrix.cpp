// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

#include <vector>

// 跑兩次二分搜尋，一次找 row 第二次找 column
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty() || matrix[0].empty())
    return false;
  if (target < matrix[0][0] || target > matrix.back().back())
    return false;

  int left = 0, right = matrix.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (matrix[mid][0] == target)
      return true;
    else if (matrix[mid][0] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  // 確認在某一 row 之後
  int row = right;
  left = 0;
  right = matrix[row].size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (matrix[row][mid] == target)
      return true;
    else if (matrix[row][mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return false;
}

// 解法二 因按照題意，輸入 2d array 可以壓縮為 有序的 1d array
// 2d[x][y] => 1d[length_of_column * x + y]
// 1d[x] => 2d[x / length_of_column][x % length_of_column]
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],  => [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 50]
//   [23, 30, 34, 50]
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty() || matrix[0].empty())
    return false;
  if (target < matrix[0][0] || target > matrix.back().back())
    return false;

  int m = matrix.size(), n = matrix[0].size();
  int left = 0, right = m * n - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (matrix[mid / n][mid % n] == target)
      return true;
    else if (matrix[mid / n][mid % n] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return false;
}