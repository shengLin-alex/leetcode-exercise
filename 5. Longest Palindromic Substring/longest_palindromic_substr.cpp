#include <iostream>
#include <string>
#include <vector>

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

using namespace std;
void searchPalindrome(string s, int i, int j, int &start, int &m_l);

string longestPalindrome(string s)
{
    if (s.size() < 2) return s;
    
    int n = s.size(), m_l = 0, start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        searchPalindrome(s, i, i, start, m_l);
        searchPalindrome(s, i, i + 1, start, m_l);
    }
    return s.substr(start, m_l);
}

void searchPalindrome(string s, int i, int j, int &start, int &m_l)
{
    while (i >= 0 && j < s.size() && s[i] == s[j]) // 取陣列的判斷式放最後才不會炸
    {
        --i;
        ++j;
    }
    if (m_l < j - i - 1)
    {
        start = i + 1;
        m_l = j - i - 1;
    }
}

int main()
{
    string s = "abcdasdfghjkldcba";

    auto res = longestPalindrome(s);

    cout << res << endl;

    return 0;
}