// A self-dividing number is a number that is divisible by every digit it contains.

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

// Also, a self-dividing number is not allowed to contain the digit zero.

// Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if
// possible.

// Example 1:
// Input:
// left = 1, right = 22
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// Note:

// The boundaries of each input argument are 1 <= left <= right <= 10000.

#include <string>
#include <vector>

using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
  vector<int> res;
  for (int i = left; i <= right; i++) {
    if (check(i)) {
      res.push_back(i);
    }
  }

  return res;
}

bool check(int num) {
  // 轉成字串一個一個處理
  string num_str = to_string(num);
  for (auto c : num_str) {
    if (c == '0' || num % (c - '0'))
      return false;
  }

  return true;
}