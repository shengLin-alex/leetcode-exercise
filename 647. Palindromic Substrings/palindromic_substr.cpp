// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:

// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
 

// Example 2:

// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Note:

// The input string length won't exceed 1000.

#include <string>

using namespace std;

int countSubstrings(string s)
{
    // 將每個字符視為中間點並延伸
    if (s.empty())
        return 0;
    int n = s.size(), res = 0;
    for (int i = 0; i < n; i++)
    {
        helper(s, i, i, res);     // s為奇數長度, 中間點為一個字符 s[i]
        helper(s, i, i + 1, res); // s為偶數長度, 中間點為兩個字符 s[i],s[i+1]
    }

    return res;
}

void helper(string s, int i, int j, int &res)
{
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        i--; // 從中間往左退
        j++; // 從中間往右進
        res++;
    }
}