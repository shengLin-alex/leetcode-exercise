// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example 1:

// Input: 4
// Output: 2
// Example 2:

// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.

#include <string>
#include <iostream>

// 解法 1. 利用 for loop 找出 < x 的數 i 最後一個 i * i 沒爆掉的
int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    int ans = 0;
    for (double i = 0; i < x; i++)
    {
        if (i * i <= x)
            ans = i;
        if (i * i > x)
            break;
    }

    return ans;
}

// 解法 2. 原理類似解法 1 ，改為用 2分搜尋
int mySqrt2(int x)
{
    if (x <= 1) return x;

    int left = 0, right = x;
    while (left < right)
    {
        int mid = (right + left) / 2;
        if (x / mid >= mid) left = mid + 1;
        else 
        {
            right = mid;
        }
    }

    return right - 1;
}

int main(int argc, char **argv)
{
    int t = std::stoi(argv[1]);
    int ans = mySqrt2(t);

    std::cout << ans << std::endl;
    return 0;
}