// We have a two dimensional matrix A where each value is 0 or 1.

// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s,
// and all 1s to 0s.

// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the
// matrix is the sum of these numbers.

// Return the highest possible score.

// Example 1:

// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation:
// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

// Note:

// 1 <= A.length <= 20
// 1 <= A[0].length <= 20
// A[i][j] is 0 or 1.

#include <cmath>
#include <vector>

using namespace std;

int matrixScore(vector<vector<int>> &A) {
  if (A.size() < 1) {
    return 0;
  }

  for (int i = 0; i < A.size(); i++) {
    // 檢查開頭為 0 必定要 01 反向
    if (A[i][0] == 0) {
      toggleX(A, i);
    }
  }

  int sum = 0;
  for (int j = 0; j < A[0].size(); j++) {
    int count1 = 0;

    // 取每列 1 的個數
    for (int k = 0; k < A.size(); k++) {
      if (A[k][j] == 1) {
        ++count1;
      }
    }

    // 解釋：1的個數較多就不用 toggle，反之要toggle
    // 而toggle 完的數量也就是 1 的個數 跟 0的個數(A.size() - count1) 比較取較多的
    count1 = A.size() - count1 > count1 ? A.size() - count1 : count1;

    // 和就是每列 1 的個數乘上 1 2 4 8(2進位轉10進位) 看在那一列
    sum += count1 * pow(2, A[0].size() - j - 1);
  }

  return sum;
}

void toggleX(vector<vector<int>> &arr, int y) {
  for (int i = 0; i < arr[y].size(); i++) {
    if (arr[y][i] == 0) {
      arr[y][i] = 1;
    } else {
      arr[y][i] = 0;
    }
  }
}