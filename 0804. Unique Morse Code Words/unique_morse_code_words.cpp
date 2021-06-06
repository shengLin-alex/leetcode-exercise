// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as
// follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

// For convenience, the full table for the 26 letters of the English alphabet is given below:

// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For
// example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a
// concatenation, the transformation of a word.

// Return the number of different transformations among all words we have.

// Example:
// Input: words = ["gin", "zen", "gig", "msg"]
// Output: 2
// Explanation:
// The transformation of each word is:
// "gin" -> "--...-."
// "zen" -> "--...-."
// "gig" -> "--...--."
// "msg" -> "--...--."

// There are 2 different transformations, "--...-." and "--...--.".
// Note:

// The length of words will be at most 100.
// Each words[i] will have length in range [1, 12].
// words[i] will only consist of lowercase letters.

#include <string>
#include <unordered_set>
#include <vector>

// 用 hash_set 相同的key會被覆蓋的特性取的最後hash_set剩下的元素個數即為答案
int uniqueMorseRepresentations(std::vector<std::string> &words) {
  std::unordered_set<std::string> hash;
  std::string morses[] = {".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                          ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                          "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

  for (auto w : words) {
    std::string tmp = "";
    for (auto c : w) {
      // 減去 'a' 即可取得該小寫字母在 morses 的正確對應
      tmp += morses[c - 'a'];
    }
    hash.insert(tmp);
  }

  return hash.size();
}