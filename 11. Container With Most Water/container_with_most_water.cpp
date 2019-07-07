#include <vector>
#include <algorithm>

// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

 
// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg


// The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

int maxArea(std::vector<int> &height) {
    int i = 0, j = height.size() - 1, m = 0;
    while (i < j) {
        int side = height[i] < height[j] ? height[i] : height[j];
        m = std::max(m, side * (j - i));

        height[i] < height[j] ? ++i : --j; // 左右哪邊高保留哪邊
    }

    return m;
}

int main() {
    std::vector<int> t = {1,8,6,2,5,4,8,3,7};
    int res = maxArea(t);

    return 0;
}