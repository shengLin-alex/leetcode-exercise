// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2
// ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

#include <unordered_map>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto num : nums)
        m[num] += 1;

    int max = 0, pos = 0;
    for (const auto &mp : m) {
        if (mp.second > max) {
            max = mp.second;
            pos = mp.first;
        }
    }

    return pos;
}