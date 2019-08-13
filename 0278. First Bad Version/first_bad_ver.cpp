// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of
// your product fails the quality check. Since each version is developed based on the previous version, all the versions
// after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following
// ones to be bad.

// You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to
// find the first bad version. You should minimize the number of calls to the API.

// Example:

// Given n = 5, and version = 4 is the first bad version.

// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true

// Then 4 is the first bad version.

#include <cstddef>

bool isBadVersion(int version) {
  if (version < 2147483647)
    return false;
  else
    return true;
}

// 這題其實有很大一部份是在考察正確的二分搜尋法取得 mid 的最佳實踐
// 通常使用 (left + right) / 2 會造成溢位
// 因此較好的方式是使用 left + (right - left) / 2 
int firstBadVersion(int n) {
  int left = 1, right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid) && !isBadVersion(mid - 1))
      return mid;

    if (isBadVersion(mid)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return left;
}

int main() {
  auto r = firstBadVersion(2147483647);

  return 0;
}