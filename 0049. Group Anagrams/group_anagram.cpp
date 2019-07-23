// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// 這題不想太多直接利用 hash_map的話很好想
// 將每一個字串 a-z 重新排序當作 key
// map 的結構為 [string:vector<string>]
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, std::vector<std::string>> map;

    for (auto s : strs) {
        std::string item = s;
        std::sort(s.begin(), s.end());
        map[s].push_back(item);
    }

    for (auto &p : map)
        res.push_back(p.second);

    return res;
}

int main() {
    std::vector<std::string> t = {"hos", "boo", "nay", "deb", "wow", "bop", "bob", "brr", "hey", "rye", "eve", "elf",
                                  "pup", "bum", "iva", "lyx", "yap", "ugh", "hem", "rod", "aha", "nam", "gap", "yea",
                                  "doc", "pen", "job", "dis", "max", "oho", "jed", "lye", "ram", "pup", "qua", "ugh",
                                  "mir", "nap", "deb", "hog", "let", "gym", "bye", "lon", "aft", "eel", "sol", "jab"};
    auto r = groupAnagrams(t);

    return 0;
}