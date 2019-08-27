// Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of
// these lengths.

// If it is impossible to form any triangle of non-zero area, return 0.

// Example 1:

// Input: [2,1,2]
// Output: 5
// Example 2:

// Input: [1,2,1]
// Output: 0
// Example 3:

// Input: [3,2,3,4]
// Output: 10
// Example 4:

// Input: [3,6,2,3]
// Output: 8

// Note:

// 3 <= A.length <= 10000
// 1 <= A[i] <= 10^6

#include <algorithm>
#include <vector>

// 非常簡單沒什麼好說
int largestPerimeter(std::vector<int> &A) {
  std::sort(A.begin(), A.end());
  int end = A.size() - 1;
  for (int i = end; i >= 2; i--) {
    if (A[i - 1] + A[i - 2] <= A[i])
      continue;

    return A[i] + A[i - 1] + A[i - 2];
  }

  return 0;
}