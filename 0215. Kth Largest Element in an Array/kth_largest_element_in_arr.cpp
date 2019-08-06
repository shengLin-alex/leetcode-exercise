// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not
// the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <vector>

using namespace std;

// 利用快速排序的 partition 來找
int findKthLargest(vector<int> &nums, int k) {
  int left = 0, right = nums.size() - 1;
  while (true) {
    int pos = partition(nums, left, right);
    if (pos == k - 1)
      return nums[pos]; // 等於第k 直接 return;
    else if (pos > k - 1)
      right = pos - 1; // 目前位置比第 k 大，找左邊
    else
      left = pos + 1; // 目前位置比第 k 小，找右邊
  }
}

// 由大排到小
int partition(vector<int> &nums, int left, int right) {
  int pivot = nums[left], l = left + 1, r = right;

  while (l <= r) {
    if (nums[l] < pivot && pivot < nums[r]) {
      swap(nums[l++], nums[r--]);
    }

    if (nums[l] >= pivot)
      l++;
    if (nums[r] <= pivot)
      r--;
  }

  swap(nums[left], nums[r]);

  return r;
}