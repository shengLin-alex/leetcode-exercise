// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.

#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    if (strs.size() < 1)
        return res;
    if (strs.size() == 1)
        return strs[0];

    string std = strs[0];
    for (int i = 0; i < std.size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            bool check = std[i] == strs[j][i];
            if (j == strs.size() - 1 && check)
            {
                res.push_back(std[i]);
            }
            else if (check)
            {
                continue;
            }
            else
            {
                return res;
            }
        }
    }
    return res;
}