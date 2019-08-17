// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 14
// Output: false

bool isPerfectSquare(int num) {
  int left = 1, right = num;
  while (left <= right) { // use <= for num = 1 situation
    int mid = left + (right - left) / 2;
    if (num / mid == mid && num % mid == 0)
      return true;

    if (num / mid > mid) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

int main() {
  auto r = isPerfectSquare(1024);

  return 0;
}