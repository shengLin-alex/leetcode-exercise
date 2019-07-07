// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:

// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:

// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> m;
    vector<int> res;
    
    // 因為intersection 所以順序會一樣
    // 所以利用 map 紀錄num1數字出現次數
    // 然後檢查num2，出現過 map次數減1
    for (auto n : nums1) m[n]++;
    for (auto n : nums2)
    {
        if (m[n]-- > 0) res.push_back(n);
    }
    return res;
}