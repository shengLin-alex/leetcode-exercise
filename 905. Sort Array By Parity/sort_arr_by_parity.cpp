// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// You may return any answer array that satisfies this condition.

// Example 1:

// Input: [3,1,2,4]
// Output: [2,4,3,1]
// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

// Note:

// 1 <= A.length <= 5000
// 0 <= A[i] <= 5000

#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int> &A)
{
    int index = 0;
    for (int i = 0; i < A.size(); i++) // 利用 index 來表示該被換到的位置
        if (A[i] % 2 == 0)
            swap(A[index++], A[i]);

    return A;
}