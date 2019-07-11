// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:

// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
// Example:

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

#include <vector>

// 從兩個陣列的尾部開始比較大小
// 大的插入後面
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // 利用三個 pointer 分別表示 nums1, nums2, 與合併號的最後一個數字位置
    int i = m - 1, j = n - 1, k = m + n -1;

    while (i >= 0 && j>=0) {
        if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }

    // 上面結束之後有可能 i 或是 j 還大0
    // j 大於 0 必須繼續將 nums2 的數字跑完
    // i 大於 0 不用管，因為 i 所指的數字本身就已經存在 nums1 裡面
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}