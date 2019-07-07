// Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

// Example 1:

// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Example 2:

// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 

// Note:

// 1 <= A.length <= 10000
// -10000 <= A[i] <= 10000
// A is sorted in non-decreasing order.

#include <vector>

class Solution {
public:
    
    // 練習快速排序
    void quicksort_helper(std::vector<int>& arr, int start, int end) {
        if (start >= end) return;
        
        int mid = arr[end];
        int left = start;
        int right = end - 1;
        
        while (left < right) {
            while(arr[left] < mid && left < right)
                left++;
            while(arr[right] >= mid && left < right)
                right--;
            
            std::swap(arr[left], arr[right]);
        }
        
        if (arr[left] >= arr[end])
            std::swap(arr[left], arr[end]);
        else
            left++;
        
        quicksort_helper(arr, start, left - 1);
        quicksort_helper(arr, left + 1, end);
    } 
    
    void quicksort(std::vector<int>& arr) {
        quicksort_helper(arr, 0, arr.size() - 1);
    }
    
    std::vector<int> sortedSquares(std::vector<int>& A) {
        for (auto& n : A) {
            if (n < 0) n *= -1;
        }
        
        quicksort(A);
        
        for (auto& n : A) {
            n *= n;
        }
        
        return A;
    }
};