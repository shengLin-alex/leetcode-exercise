// In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well.

// At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.

// What is the maximum total sum that the height of the buildings can be increased?

// Example:
// Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
// Output: 35
// Explanation:
// The grid is:
// [ [3, 0, 8, 4],
//   [2, 4, 5, 7],
//   [9, 2, 6, 3],
//   [0, 3, 1, 0] ]

// The skyline viewed from top or bottom is: [9, 4, 8, 7]
// The skyline viewed from left or right is: [8, 7, 9, 3]

// The grid after increasing the height of buildings without affecting skylines is:

// gridNew = [ [8, 4, 8, 7],
//             [7, 4, 7, 7],
//             [9, 4, 8, 7],
//             [3, 3, 3, 3] ]

// Notes:

// 1 < grid.length = grid[0].length <= 50.
// All heights grid[i][j] are in the range [0, 100].
// All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.

#include <vector>
#include <algorithm>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{
    vector<vector<int>> trans;

    // 將原本 grid 行列互換暫存為 trans 用於比較
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> temp;

        for (int j = 0; j < grid.size(); j++)
        {
            temp.push_back(grid[j][i]);
        }

        trans.push_back(temp);
    }

    int sum = 0;
    // 對 grid[i][j] 來說可以增加到的最大值為 grid[i][j] 同列最大值與同行最大值比較取小的
    for (int i = 0; i < grid.size(); i++)
    {
        // 取得 x 最大
        int maxX = *max_element(grid[i].begin(), grid[i].end());
        int sumInner = 0;

        for (int j = 0; j < grid.size(); j++)
        {
            // 取得 y 最大
            int maxY = *max_element(trans[j].begin(), trans[j].end());

            if (maxX > maxY)
            {
                grid[i][j] = maxY - grid[i][j];
            }
            else
            {
                grid[i][j] = maxX - grid[i][j];
            }

            sumInner += grid[i][j];
        }
        sum += sumInner;
    }

    return sum;
}