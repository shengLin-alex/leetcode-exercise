// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the
// non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.

#include <iostream>
#include <vector>
using namespace std;

// void moveZeroes(vector<int> &nums)
// {
//     int count0 = 0;
//     int i = 0;
//     while (i < nums.size())
//     {
//         if (nums[i] == 0)
//         {
//             ++count0;
//             nums.erase(nums.begin() + i);
//             i = 0;
//         }
//         else
//         {
//             i++;
//         }
//     }

//     for (int j = 0; j < count0; j++)
//     {
//         nums.push_back(0);
//     }
// }

// better approach
void moveZeroes(vector<int> &nums) {
    int n = nums.size(), zero_pos = -1;
    for (int i = 0; i < n; i++) {
        // 取得 0 的位置
        if (nums[i] == 0 && zero_pos == -1)
            zero_pos = i;

        // 遇到非 0 跟目前 0的位置互換
        // 0的位置往下移動
        if (nums[i] != 0 && zero_pos != -1)
            swap(nums[i], nums[zero_pos++]);
    }
}

int main() {
    vector<int> t{1, 2, 3, 4, 0, 5, 6};
    moveZeroes(t);

    for (auto n : t) {
        cout << n;
    }

    return 0;
}