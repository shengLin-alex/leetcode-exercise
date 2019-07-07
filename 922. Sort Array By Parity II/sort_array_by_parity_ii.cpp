// Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

// Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

// You may return any answer array that satisfies this condition.

 

// Example 1:

// Input: [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 

// Note:

// 2 <= A.length <= 20000
// A.length % 2 == 0
// 0 <= A[i] <= 1000

#include <vector>
#include <algorithm>

// 偶數要再偶數位置 (0 2 4...)
std::vector<int> sortArrayByParityII(std::vector<int>& A) {
    int idx = 0, len = A.size();
    for (int i = 0; i < len; i++) {
        if (A[i] % 2 == 0) {
            std::swap(A[idx++], A[i]);
        }
    }

    // 陣列個數為奇數
    if ((len / 2) % 2 != 0) {
        for (int i = 0; i < len / 2; i++)
            if (i % 2 != 0) 
                std::swap(A[i], A[i + len / 2]);
    } else { // 為偶數
        for (int i = 0; i < len / 2; i++)
            if (i % 2 != 0) 
                std::swap(A[i], A[i + len / 2 - 1]);
    }
        
    return A;
}

int main() {
    std::vector<int> t = {3,0,4,0,2,1,3,1};
    auto r = sortArrayByParityII(t);

    return 0;
}