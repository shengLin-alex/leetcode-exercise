// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of
// all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of
// space complexity analysis.)

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 移除自己然後其餘相乘的硬幹法，不給過，寫太爛
// vector<int> productExceptSelf(vector<int>& nums) {
//     int len = nums.size();
//     vector<stack<int, vector<int>>> expect_self;

//     for (int i = 0; i < len; i++) {
//         int temp = nums[i];
//         nums.erase(nums.begin() + i);
//         stack<int, vector<int>> a(nums);
//         expect_self.push_back(a);
//         nums.insert(nums.begin() + i, temp);
//     }
//     vector<int> b;
//     int product = 1;
//     for (auto set : expect_self) {
//         while (!set.empty()) {
//             product *= set.top();
//             set.pop();
//         }
//         b.push_back(product);
//         product = 1;
//     }

//     return b;
// }

// 類似動態規劃的方式
// 自己前面的相乘跟後面的相乘，再相乘
vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  // 設定 fwd 為某位置(i)前的數字相乘
  // bwd 為某位置(i)後的數字相乘
  // res 為除了某位置(i)之外的所有數字相乘
  vector<int> fwd(n, 1), bwd(n, 1), res(n);

  for (int i = 0; i < n - 1; ++i) {
    // i = 0
    // fwd[1] = fwd[0] * nums[0];
    // i = 1
    // fwd[2] = fwd[1] * nums[1];
    // ...
    fwd[i + 1] = fwd[i] * nums[i];
  }
  for (int i = n - 1; i > 0; --i) {
    // i = 6
    // fwd[5] = fwd[6] * nums[6];
    // i = 5
    // fwd[4] = fwd[5] * nums[5];
    // ...
    bwd[i - 1] = bwd[i] * nums[i];
  }
  for (int i = 0; i < n; ++i) {
    res[i] = fwd[i] * bwd[i];
  }

  return res;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  productExceptSelf(arr);

  return 0;
}