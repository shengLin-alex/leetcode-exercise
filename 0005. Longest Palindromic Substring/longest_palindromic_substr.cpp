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

void searchPalindrome(string s, int left, int right, int &start, int &m_l)
{
    while (left >= 0 && right < s.size() && s[left] == s[right]) // 取陣列的判斷式放最後才不會炸
    {
        --left; // 往左邊擴大
        ++right; // 往右邊擴大
    }
    if (m_l < right - left - 1)
    {
        start = left + 1; // subtstr 的起頭此時為 left + 1，s[left]這時候已經不符合 palindromic
        m_l = right - left - 1; // 取得 substr 的長度
    }
}

// 遍厲每個字符，將每個字符當作 middle 並且two pointers左右擴大，若字符一樣繼續擴大
string longestPalindrome(string s)
{
    if (s.size() < 2) return s;
    
    int n = s.size(), m_l = 0, start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        searchPalindrome(s, i, i, start, m_l); // 字串長度奇數時 'xx(x)xx' middle = left = right
        searchPalindrome(s, i, i + 1, start, m_l); // 長度偶數十 'xx(xx)xx' middle => left & left + 1(right)
    }
    
    return s.substr(start, m_l);
}

int main()
{
    string s = "abcdasdfghjkldcba";

    auto res = longestPalindrome(s);

    cout << res << endl;

    return 0;
}