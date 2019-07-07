// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <vector>
#include <iostream>

// dp[0] = 1;
// dp[1] = 1;
//
// dp[2] =   dp[0] * dp[1]
//         + dp[1] * dp[0];
//
// dp[3] =   dp[0] * dp[2]
//         + dp[1] * dp[1]
//         + dp[2] * dp[0];
//
// or use 卡特蘭數公式 c(2n, n)/(n+1)
int numTrees(int n) {
    if (n < 2) return 1;
        
    std::vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) dp[i] += dp[j] * dp[i - j - 1];
    }
        
    return dp[n];
}

int main() {
    auto r = numTrees(6);

    return 0;
}