// Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

// To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0]
// horizontally results in [0, 1, 1].

// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1]
// results in [1, 0, 0].

// Example 1:

// Input: [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
// Example 2:

// Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Notes:

// 1 <= A.length = A[0].length <= 20
// 0 <= A[i][j] <= 1

#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
  int len = A.size();

  // 每組先01反向
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (A[i][j] == 0)
        A[i][j] = 1;
      else
        A[i][j] = 0;
    }
  }

  // 在左右反轉
  for (int i = 0; i < len; i++) {
    int r = 0, l = A[i].size() - 1;
    while (r <= l)
      swap(A[i][r++], A[i][l--]);
  }

  return A;
}