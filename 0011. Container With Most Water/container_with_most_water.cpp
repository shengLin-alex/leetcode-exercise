#include <algorithm>
#include <vector>

// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (left, ai). n vertical
// lines are drawn such that the two endpoints of line left is at (left, ai) and (left, 0). Find two lines, which
// together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg

// The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue
// section) the container can contain is 49.

// 利用 two pointers 代表左右兩邊的邊
int maxArea(std::vector<int> &height) {
    int left = 0, right = height.size() - 1, m = 0;
    while (left < right) {
        // 由於計算容積所以要取小的邊來乘
        int side = height[left] < height[right] ? height[left] : height[right];
        m = std::max(m, side * (right - left));

        height[left] < height[right] ? ++left : --right; // 左右哪邊高保留哪邊
    }

    return m;
}

int main() {
    std::vector<int> t = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = maxArea(t);

    return 0;
}