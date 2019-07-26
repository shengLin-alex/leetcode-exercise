// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <string>
#include <vector>

using namespace std;

void dfs(vector<string> &sols, string sol, int left, int right) {
  if (left > right)
    return; // 表示 right 使用數量過多已經超過left，不符合規則 ex. "())"

  // 左右都剛好用完的就是一組解答
  if (left == 0 && right == 0)
    sols.push_back(sol);
  else {
    if (left > 0)
      dfs(sols, sol + '(', left - 1, right);
    if (right > 0)
      dfs(sols, sol + ')', left, right - 1);
  }
}

// n 代表組數 => 表示開括號與閉括號個需要 n 個
// 利用遞迴深度優先往左邊寫入開括號
// 在回朔寫閉括號
vector<string> generateParenthesis(int n) {
  vector<string> res;
  dfs(res, "", n, n);
  return res;
}

int main(int argc, char **argv) {
  int t = stoi(string(argv[1]));
  auto res = generateParenthesis(t);

  return 0;
}