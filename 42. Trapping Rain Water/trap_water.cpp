// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png

// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

#include <vector>
#include <iostream>
#include <algorithm>

int trap(std::vector<int> &height) {
    if (height.size() < 3) return 0;

    int ans = 0;
    int size = height.size();

    std::vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];

    // 從i往左邊看過去的最高點
    for (int i = 1; i < size; i++) {
        left_max[i] = std::max(height[i], left_max[i - 1]);
    }

    right_max[size - 1] = height[size - 1];

    // 從i往右邊看過去的最高點
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = std::max(height[i], right_max[i + 1]);
    }

    // 取較矮的一邊減去原始高度，低窪區會得到水容量
    // https://leetcode.com/problems/trapping-rain-water/Figures/42/trapping_rain_water.png
    for (int i = 1; i < size - 1; i++) {
        ans += std::min(left_max[i], right_max[i]) - height[i];
    }

    return ans;
}

int main() {
    std::vector<int> t = {0,1,0,2,1,0,1,3,2,1,2,1};

    auto res = trap(t);

    std::cout << res << std::endl;

    return 0;
}