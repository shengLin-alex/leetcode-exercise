// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:

// Each element in the result must be unique.
// The result can be in any order.

#include <unordered_set>
#include <vector>

// 按照題意，利用 hash set的特性排除重複數字
// 對陣列二元素取出檢查是否存在於陣列一轉換之 hash set
// 存在的話加入另一hash set (由於 hash set 之特性重複會被排除因此可以遍歷 nums2 直接 insert即可)
std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::unordered_set<int> s1(nums1.begin(), nums1.end()), res;

    for (auto n : nums2) {
        if (s1.count(n))
            res.insert(n);
    }

    return std::vector<int>(res.begin(), res.end());
}