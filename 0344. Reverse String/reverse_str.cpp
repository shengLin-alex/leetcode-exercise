// Write a function that reverses a string. The input string is given as an array of characters char[].

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra
// memory.

// You may assume all the characters consist of printable ascii characters.

// Example 1:

// Input: ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

#include <string>
#include <vector>

void reverseString(std::vector<char> &s) {
  int left = 0, right = s.size() - 1;
  while (left < right)
    std::swap(s[left++], s[right--]);
}

int main() {
  std::string str = "fuck";
  std::vector<char> input(str.begin(), str.end());
  reverseString(input);

  return 0;
}