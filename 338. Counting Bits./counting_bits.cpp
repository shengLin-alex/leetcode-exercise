// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example 1:

// Input: 2
// Output: [0,1,1]
// Example 2:

// Input: 5
// Output: [0,1,1,2,1,2]
// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

// 0    0000    0
// -------------
// 1    0001    1
// -------------
// 2    0010    1
// 3    0011    2
// -------------
// 4    0100    1
// 5    0101    2
// 6    0110    2
// 7    0111    3
// -------------
// 8    1000    1
// 9    1001    2
// 10   1010    2
// 11   1011    3
// 12   1100    2
// 13   1101    3
// 14   1110    3
// 15   1111    4
vector<int> countBits(int num)
{
    if (num == 0)
        return {0};
    vector<int> res{0, 1};
    int k = 2, i = 2;
    while (i <= num)
    {
        for (i = pow(2, k - 1); i < pow(2, k); ++i)
        {
            if (i > num)
                break;
            int t = (pow(2, k) - pow(2, k - 1)) / 2;
            if (i < pow(2, k - 1) + t)
                res.push_back(res[i - t]);
            else
                res.push_back(res[i - t] + 1);
        }
        ++k;
    }
    return res;
}

// use bitset
vector<int> countBits(int num)
{
    vector<int> res;
    for (int i = 0; i <= num; ++i)
    {
        res.push_back(bitset<32>(i).count());
    }
    return res;
}

// i    binary '1'  i&(i-1)
// 0    0000    0
// -----------------------
// 1    0001    1    0000
// -----------------------
// 2    0010    1    0000
// 3    0011    2    0010
// -----------------------
// 4    0100    1    0000
// 5    0101    2    0100
// 6    0110    2    0100
// 7    0111    3    0110
// -----------------------
// 8    1000    1    0000
// 9    1001    2    1000
// 10   1010    2    1000
// 11   1011    3    1010
// 12   1100    2    1000
// 13   1101    3    1100
// 14   1110    3    1100
// 15   1111    4    1110
vector<int> countBits(int num)
{
    vector<int> res(num + 1, 0);
    for (int i = 1; i <= num; ++i)
    {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}