// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    int res = 0;
    std::unordered_set<int> set(nums.begin(), nums.end());
        
    for (auto n : nums) {
        if (!set.count(n)) continue;
            
        set.erase(n);
        int left = n - 1; // n的左邊
        int right = n + 1; // n的右邊
            
        while(set.count(left)) set.erase(left--); // 最大限度擴展左邊
        while(set.count(right)) set.erase(right++); // 最大限度擴展右邊
            
        res = std::max(res, right - left - 1); // 此時的左右都不在集合中，所以要再減一
    }
        
    return res;
}

int main() {
    std::vector<int> t = {100, 4, 200, 1, 3, 2};

    auto res = longestConsecutive(t);

    return 0;
}