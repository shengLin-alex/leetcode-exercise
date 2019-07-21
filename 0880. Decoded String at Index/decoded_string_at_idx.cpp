// An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

// If the character read is a letter, that letter is written onto the tape.
// If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
// Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

 

// Example 1:

// Input: S = "leet2code3", K = 10
// Output: "o"
// Explanation: 
// The decoded string is "leetleetcodeleetleetcodeleetleetcode".
// The 10th letter in the string is "o".
// Example 2:

// Input: S = "ha22", K = 5
// Output: "h"
// Explanation: 
// The decoded string is "hahahaha".  The 5th letter is "h".
// Example 3:

// Input: S = "a2345678999999999999999", K = 1
// Output: "a"
// Explanation: 
// The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
 

// Note:

// 2 <= S.length <= 100
// S will only contain lowercase letters and digits 2 through 9.
// S starts with a letter.
// 1 <= K <= 10^9
// The decoded string is guaranteed to have less than 2^63 letters.

#include <string>

std::string decodeAtIndex(std::string S, int K) {
    long i = 0, count = 0;
    // 取得解碼後的字串長度，由於為了避免炸掉，只需要取到剛到大於K的時候即可
    for (; count < K; i++) {
        // 遇到數字則乘以該數字即為當前解碼之長度
        // 遇到字母則繼續延長本身長度
        count = std::isdigit(S[i]) ? count *= S[i] - '0' : count + 1;
    }

    // 從後面開始往前利用除法取規律並找出目標字符
    // 讓 count 長度持續縮小直到 K 能整除 count
    while (i--) { // 此時 i 的位置為長度剛好大於等於 K時的下一個位置
        if (std::isdigit(S[i])) {
            count /= S[i] - '0'; // 從後往前遍厲遇到數字表示該數字前的字串出現了 S[i] 次
            K %= count; // K 有可能已經大於 count，因此直接取餘數即可表示循環之後的位置
        } else {
            if (K % count == 0) return std::string(1, S[i]);
            count--;
        }
    }

    return "";
}

int main() {
    auto r = decodeAtIndex("ixm5xmgo78", 711);

    return 0;
}