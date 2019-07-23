// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than
// 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

#include <string>
#include <vector>

using namespace std;

bool isAnagrams(string target, string pattern);

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int len = s.size() - p.size();
    int size = p.size();
    for (int i = 0; i <= len; i++) {
        if (isAnagrams(s.substr(i, size), p)) {
            res.push_back(i);
        }
    }
    return res;
}

bool isAnagrams(string target, string pattern) {
    int hash[26] = {0};
    for (auto c : target)
        hash[c - 'a']++;
    for (auto c : pattern)
        hash[c - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (hash[i] != 0)
            return false;
    }

    return true;
}

// a better approach
vector<int> findAnagrams(string s, string p) {
    if (s.empty())
        return {};

    vector<int> res, t1(256, 0), t2(256, 0);
    for (int i = 0; i < p.size(); i++) {
        ++t1[s[i]];
        ++t2[p[i]];
    }
    if (t1 == t2)
        res.push_back(0);

    for (int i = p.size(); i < s.size(); i++) {
        ++t1[s[i]];            // push one more char to right
        --t1[s[i - p.size()]]; // remove one more char from left

        if (t1 == t2)
            res.push_back(i - p.size() + 1); // i means last char pos so - p.size() + 1
    }
    return res;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    auto res = findAnagrams(s, p);

    return 0;
}