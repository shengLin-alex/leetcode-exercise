// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the
// result equals B.

// Example 1:

// Input: A = "ab", B = "ba"
// Output: true
// Example 2:

// Input: A = "ab", B = "ab"
// Output: false
// Example 3:

// Input: A = "aa", B = "aa"
// Output: true
// Example 4:

// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:

// Input: A = "", B = "aa"
// Output: false

// Note:

// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist only of lowercase letters.

#include <string>
#include <unordered_set>
#include <vector>

// aaa aaa true
// aab aab true
// ab ba true
// ab ba false
// abab abab true
// ababc ababc true
bool buddyStrings(std::string A, std::string B) {
  if (A.size() != B.size()) // must same size
    return false;

  int removeDupLen = std::unordered_set<char>(A.begin(), A.end()).size();
  if (A == B && removeDupLen < B.size()) // check duplicate letter string but A == B
    return true;

  std::vector<int> diffs;
  for (int i = 0; i < A.size(); i++) { // should be excatly two diff
    if (A[i] != B[i])
      diffs.push_back(i);

    if (diffs.size() > 2)
      return false;
  }

  return diffs.size() == 2 && A[diffs[0]] == B[diffs[1]] && A[diffs[1]] == B[diffs[0]];
}