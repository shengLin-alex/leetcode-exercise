// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <vector>

// 基本上和 combination sum 思度差不多
// 只是組合不接收重複排列因此需要設定條件
void backtracking(std::vector<std::vector<int>> &sol, std::vector<int> &res, int n, int k, int idx, int dim) {
  if (dim == k) { // 當維度等於 k 時表示為一組解
    sol.push_back(res);
    return;
  }

  for (int i = idx; i <= n; i++) {
    int len = res.size();
    // i >= idx 時表示正在選第二個以後的數字且res[len - 1] >= i時表示正在找重複的排列組合
    if (i >= idx && len > 0 && res[len - 1] >= i)
      continue;

    res.push_back(i);
    backtracking(sol, res, n, k, idx + 1, dim + 1);
    res.pop_back();
  }
}

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<int> res;
  std::vector<std::vector<int>> sol;
  backtracking(sol, res, n, k, 1, 0);

  return sol;
}

int main() {
  auto r = combine(5, 3);

  return 0;
}