// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all
// the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not
// exist, output -1 for this number.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output
//     -1. For number 1 in the first array, the next greater number for it in the second array is 3. For number 2 in the
//     first array, there is no next greater number for it in the second array, so output -1.
// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
// Note:
// All elements in nums1 and nums2 are unique.
// The length of both nums1 and nums2 would not exceed 1000.

#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  vector<int> res(nums1.size(), -1);
  unordered_map<int, int> mp;
  for (int i = 0; i < nums2.size(); i++)
    mp[nums2[i]] = i;

  for (int i = 0; i < nums1.size(); i++) {
    for (int j = mp[nums1[i]]; j < nums2.size(); j++) {
      if (nums2[j] > nums1[i]) {
        res[i] = nums2[j];
        break;
      }
    }
  }

  return res;
}

int main() {
  vector<int> n1 = {4, 1, 2};
  vector<int> n2 = {1, 3, 4, 2};

  auto n = nextGreaterElement(n1, n2);

  return 0;
}