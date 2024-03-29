// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.

// Example 1:

// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include <iostream>
#include <vector>

// 爬 N 階相當於爬 N-1 + N-2 的結果
// 這題用遞迴會被拒絕 太慢
int climbStairs(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  n++;
  int first = 1, second = 1, third = 0, i = 2;
  while (i < n) {
    third = first + second;
    first = second;
    second = third;
    i++;
  }

  return third;
}

int main(int argc, char **argv) {
  auto res = climbStairs(std::stoi(std::string(argv[1])));

  std::cout << res << std::endl;

  return 0;
}