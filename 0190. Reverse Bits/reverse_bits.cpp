// Reverse bits of a given 32 bits unsigned integer.

// Example 1:

// Input: 00000010100101000001111010011100
// Output: 00111001011110000010100101000000
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so
// return 964176192 which its binary representation is 00111001011110000010100101000000. Example 2:

// Input: 11111111111111111111111111111101
// Output: 10111111111111111111111111111111
// Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so
// return 3221225471 which its binary representation is 10101111110010110010011101101001.

// Note:

// Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will
// be given as signed integer type and should not affect your implementation, as the internal binary representation of
// the integer is the same whether it is signed or unsigned. In Java, the compiler represents the signed integers using
// 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output
// represents the signed integer -1073741825.

#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) { // 輸入為 32 位元
        if (n & 1 == 1) {          // 每次 & 1 檢查最右邊位元是否為 1
            res = (res << 1) + 1;  // 為 1 則將 res 左移 1(x2) 並 + 1
        } else {
            res = res << 1; // 為 0 只須左移 1(x2)
        }

        n = n >> 1; // 將輸入右移 1，讀取下一個位元
    }

    return res;
}

int main() {
    auto r = reverseBits(4); // 00000000000000000000000000000100

    return 0;
}