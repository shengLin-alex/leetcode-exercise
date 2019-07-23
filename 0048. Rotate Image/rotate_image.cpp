// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Note:

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate
// another 2D matrix and do the rotation.

// Example 1:

// Given input matrix =
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Example 2:

// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ],

// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix) {
    int size = matrix.size();

    // 對角線翻轉
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i; j++) {
            std::swap(matrix[i][j], matrix[size - 1 - j][size - 1 - i]);
        }
    }

    // 在從中間上下翻轉
    for (int i = 0; i < size / 2; i++) {
        for (int j = 0; j < size; j++) {
            std::swap(matrix[i][j], matrix[size - 1 - i][j]);
        }
    }
}

int main() {
    std::vector<std::vector<int>> t = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

    rotate(t);

    return 0;
}