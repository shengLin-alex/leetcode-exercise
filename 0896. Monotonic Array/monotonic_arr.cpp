// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <=
// j, A[i] >= A[j].

// Return true if and only if the given array A is monotonic.

// Example 1:

// Input: [1,2,2,3]
// Output: true
// Example 2:

// Input: [6,5,4,4]
// Output: true
// Example 3:

// Input: [1,3,2]
// Output: false
// Example 4:

// Input: [1,2,4,5]
// Output: true
// Example 5:

// Input: [1,1,1]
// Output: true

// Note:

// 1 <= A.length <= 50000
// -100000 <= A[i] <= 100000

#include <vector>

// 本題算是考察布林邏輯思考
// 若 one pase 後同時出現 inc dec 表示非題意所求 return false
bool isMonotonic(std::vector<int> &A) {
  bool inc = false, dec = false;
  for (int i = 1; i < A.size(); i++) {
    if (A[i] < A[i - 1]) {
      dec = true;
    }

    if (A[i] > A[i - 1]) {
      inc = true;
    }
  }

  return inc && dec ? false : true;
}