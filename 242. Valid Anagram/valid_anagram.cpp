// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    int st[26] = {0}, tt[26] = {0};
    for (int i = 0; i < s.size(); i++)
        ++st[s[i] - 'a']; // 統計 a-z
    for (int j = 0; j < t.size(); j++)
        ++tt[t[j] - 'a'];
    for (int t = 0; t < 26; t++)
        if (st[t] != tt[t])
            return false;

    return true;
}

// 上面的可以再優化
bool isAangramOpt(string s, string t)
{
    if (s.size() != t.size()) return false;

    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++; // s出現過得加一
        count[t[i] - 'a']--; // t出現過減一
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (count[s[i] - 'a'] != 0) return false; // 不等於0等於沒有吻合
    }

    return true;
}

int main(int argc, char **argv)
{
    bool res = isAnagram(string(argv[1]), string(argv[2]));
    cout << res << endl;
    return 0;
}