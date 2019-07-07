// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// 用 hash map 紀錄次數
int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    for (auto c : s)
        ++m[c];
    for (auto c : s)
        if (m[c] == 1)
            return s.find(c);

    return -1;
}

// 利用陣列[26] 紀錄字母表
int v2(string s)
{
    vector<int> table(26);
    for (int i = 0; i < s.size(); i++)
    {
        table[s[i] - 'a']++; // 減掉'a'代表該字母在字母表位置
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (table[s[i] - 'a'] == 1)
            return i;
    }

    return -1;
}

int main()
{
    string t = "leetcode";
    int res = firstUniqChar(t);

    return 0;
}