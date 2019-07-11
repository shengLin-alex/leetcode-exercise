// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note: You are not suppose to use the library's sort function for this problem.

// Example:

// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Follow up:

// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// Could you come up with a one-pass algorithm using only constant space?

// 目標：one pass O(n), O(1) space
#include <vector>

// two pass(其實沒多慢但是多用了一個陣列計算顏色出現次數)
void sortColors(std::vector<int>& nums) {
    std::vector<int> t(3,0);
    for (auto n : nums) t[n]++;
    for (int i = 0, cur = 0; i < 3; i++) {
        for (int j = 0; j < t[i]; j++)
            nums[cur++] = i;
    }
}

// two pointer
void sortColors(std::vector<int>& nums) {
    int red = 0, blue = nums.size() - 1, cur = 0;

    while (cur <= blue) {
        if (nums[cur] == 0) { // 遇到0與red交換位置並且 cursor 往下移動
            std::swap(nums[cur++], nums[red++]);
        } else if (nums[cur] == 2) { // 遇到 2 與 blue 交換位置，cursor 不移動因為可能需要繼續比對
            std::swap(nums[cur], nums[blue--]);
        } else { // 遇到 1 不管直接往下移動
            cur++;
        }
    }
}