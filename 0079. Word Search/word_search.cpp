// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
// or vertically neighboring. The same letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include <string>
#include <vector>

bool dfs(std::vector<std::vector<char>> &board, std::string word, std::vector<std::vector<bool>> &visited, int idx,
         int i, int j, int m, int n) {
  if (idx >= word.size()) // means finish the search
    return true;

  // 前四個條件檢查座標是否合法
  // 檢查是否訪問過
  // 檢查該訪問字元是否符合當前 word 遍歷之字元
  if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx])
    return false;

  visited[i][j] = true;
  bool result = // 搜尋上下左右
      dfs(board, word, visited, idx + 1, i - 1, j, m, n) || dfs(board, word, visited, idx + 1, i + 1, j, m, n) ||
      dfs(board, word, visited, idx + 1, i, j - 1, m, n) || dfs(board, word, visited, idx + 1, i, j + 1, m, n);
  visited[i][j] = false;

  return result;
}

// 也可以不使用 visited 直接註記在原 board
bool dfs(std::vector<std::vector<char>> &board, std::string word, int idx, int i, int j, int m, int n) {
  if (idx >= word.size()) // means finish the search
    return true;

  // 前四個條件檢查座標是否合法
  // 檢查是否訪問過
  // 檢查該訪問字元是否符合當前 word 遍歷之字元
  if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
    return false;

  char cur = board[i][j];
  board[i][j] = '*'; // mark as visited
  bool result =      // 搜尋上下左右
      dfs(board, word, idx + 1, i - 1, j, m, n) || dfs(board, word, idx + 1, i + 1, j, m, n) ||
      dfs(board, word, idx + 1, i, j - 1, m, n) || dfs(board, word, idx + 1, i, j + 1, m, n);
  board[i][j] = cur; // backtrack

  return result;
}

// 標準 dfs 利用 visited 註記訪問與否
bool exist(std::vector<std::vector<char>> &board, std::string word) {
  if (board.empty() || board[0].empty())
    return false;

  int m = board.size(), n = board[0].size();
  // std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (dfs(board, word, 0, i, j, m, n))
        return true;
    }
  }

  return false;
}