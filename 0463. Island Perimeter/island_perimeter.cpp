// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and
// there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a
// square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the
// island.

// Example:

// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Output: 16

// Explanation: The perimeter is the 16 yellow stripes in the image below:

// https://assets.leetcode.com/uploads/2018/10/12/island.png

#include <vector>

// 直觀的作法，檢查每一格 1 的上下左右數邊
// 不過其實有一個用公式的解法
// 節錄自 leetcode
// 1.计算所有方格的周长之和
// 2.减去方格相接因而不算入周长的部分，由于相接会同时减少两个相接方格的周长，故每一单位长度都要乘以2
// 3.先计算横向相接的长度，再计算纵向相接的长度
int islandPerimeter(std::vector<std::vector<int>> &grid) {
  if (grid.empty() || grid[0].empty())
    return 0;

  int m = grid.size(), n = grid[0].size(), cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0)
        continue;
      
      int tmp = 0;
      if (j - 1 >= 0 && grid[i][j - 1] == 0) {
        tmp++;
      } else if (j - 1 < 0) {
        tmp++;
      }

      if (j + 1 < n && grid[i][j + 1] == 0) {
        tmp++;
      } else if (j + 1 >= n) {
        tmp++;
      }

      if (i - 1 >= 0 && grid[i - 1][j] == 0) {
        tmp++;
      } else if (i - 1 < 0) {
        tmp++;
      }

      if (i + 1 < m && grid[i + 1][j] == 0) {
        tmp++;
      } else if (i + 1 >= m) {
        tmp++;
      }

      cnt += tmp;
    }
  }

  return cnt;
}