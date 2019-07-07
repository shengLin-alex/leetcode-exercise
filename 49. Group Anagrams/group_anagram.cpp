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

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, std::vector<std::string>> map;
    
    // 媽蛋 其實用sort 比較快
    for (auto s : strs) {
        std::vector<int> table(26, 0);
        std::string item = s;
        std::sort(s.begin(), s.end());
        map[s].push_back(item);
    }

    for (auto& p : map) res.push_back(p.second);

    return res;
}

int main() {
    std::vector<std::string> t = {"hos","boo","nay","deb","wow","bop","bob","brr","hey","rye","eve","elf","pup","bum","iva","lyx","yap","ugh","hem","rod","aha","nam","gap","yea","doc","pen","job","dis","max","oho","jed","lye","ram","pup","qua","ugh","mir","nap","deb","hog","let","gym","bye","lon","aft","eel","sol","jab"};
    auto r = groupAnagrams(t);

    return 0;
}