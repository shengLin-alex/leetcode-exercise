// Let's call an array A a mountain if the following properties hold:

// A.length >= 3
// There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
// Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
// A[A.length - 1].

// Example 1:

// Input: [0,1,0]
// Output: 1
// Example 2:

// Input: [0,2,1,0]
// Output: 1
// Note:

// 3 <= A.length <= 10000
// 0 <= A[i] <= 10^6
// A is a mountain, as defined above.

#include <vector>

int peakIndexInMountainArray(std::vector<int> &A) {
  int n = A.size();
  int left = 0, right = n - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (A[mid] < A[mid + 1]) // 峰值在 mid 右邊
      left = mid + 1;
    else if (A[mid] < A[mid - 1]) // 峰值在 mid 左邊或是就是 mid
      right = mid;
    else
      return mid;
  }

  return -1;
}