// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// Example:

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// Given target = 20, return false.

#include <vector>

// 解法 1. 通過比較 tricky 的方式
// 從左下角當起點，與 target 相比較小往上，較大往右，直到找到 target 或找不到為止
// 也可以從右上角開始操作相反
// 複雜度 O(m + n)
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty() || matrix[0].empty())
    return false;

  int m = matrix.size(), n = matrix[0].size();
  int x = 0, y = m - 1; // cursor

  while (x < n && y >= 0) {
    if (matrix[y][x] > target)
      y--;
    else if (matrix[y][x] < target)
      x++;
    else
      return true;
  }

  return false;
}

// 解法2. 通過 for loop 與二分搜尋法
// 複雜度 O(m * Log n)
bool search(std::vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target)
      return true;
    else if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return false;
}

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty() || matrix[0].empty())
    return false;

  for (int i = 0; i < matrix.size(); i++) {
    if (search(matrix[i], target))
      return true;
  }

  return false;
}

int main() {
  std::vector<std::vector<int>> t{
      {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

  auto r = searchMatrix(t, 5);

  return 0;
}