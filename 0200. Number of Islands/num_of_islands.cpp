// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water
// and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are
// all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

#include <vector>

void dfs(std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visited, int x, int y) {
  // x y 已經超出座標範圍或者該座標已經訪問過或者該座標為0時 return
  if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0')
    return;

  visited[x][y] = true; // 將該座標設為已經訪問
  // 訪問該座標上下左右
  dfs(grid, visited, x - 1, y);
  dfs(grid, visited, x + 1, y);
  dfs(grid, visited, x, y - 1);
  dfs(grid, visited, x, y + 1);
}

// 這個題目的本質是在求連續 1 的區域數量，利用 dfs 遞迴求解
int numIslands(std::vector<std::vector<char>> &grid) {
  if (grid.empty() || grid[0].empty())
    return 0;

  int m = grid.size(), n = grid[0].size(), res = 0;
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '0' || visited[i][j])
        continue;

      dfs(grid, visited, i, j);
      res++; // 出遞迴之後表示已經訪問過某一個連續區域可以加1
    }
  }

  return res;
}

int main() {
  std::vector<std::vector<char>> t = {
      {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
  auto r = numIslands(t);

  return 0;
}