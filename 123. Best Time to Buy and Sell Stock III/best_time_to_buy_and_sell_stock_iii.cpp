// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

#include <vector>
#include <climits>

// 解法 1.
// 將題目想成：最多 k 次交易的最大利潤
// => k = 2，即為本題解答
// 使用動態規劃：
// 定義兩個轉移方程： global & local
// global[i][j]：到第 i 天，進行 j 次交易之最大利潤
// local[i][j]：到第 i 天，進行 j 次交易("且"最後一次交易是在第 i 天賣出)之最大利潤
// =>
// global[i][j] = max(local[i][j], global[i - 1][j]) 比較 local在第 i 天與 global 在 i - 1 天之利潤(i - 1是因為如果取 i 那一定包含到 local[i])
//
// local[i][j] = max(global[i - 1][j - 1], max(diff,0), local[i - 1][j] + diff)
// global[i - 1][j - 1], max(diff,0) => 第 i 天前一天並少一次交易的 global 利潤加上最後一次(i,j)的正交易
// local[i - 1][j] + diff => local[i - 1][j] 的意思比較難理解，在 i 前一天進行 j 次交易後的最大利潤，加讓diff，這個diff 就是最後一次的交易，所以才取"[j]"，同時不管diff是正是負都必須加上才符合轉移方程的條件
int maxProfit(std::vector<int>& prices) {
    if (prices.empty()) return 0;

    int len = prices.size();
    std::vector<std::vector<int>> g(len, std::vector<int>(3, 0)), l(len, std::vector<int>(3, 0));
    for (int i = 1; i < len; i++) {
        int diff = prices[i] - prices[i - 1];
        for (int j = 1; j <= 2; j++) {
            // 注意：必須先計算 local 才能正確取得 global
            l[i][j] = std::max(g[i - 1][j - 1] + std::max(diff, 0), l[i - 1][j] + diff);
            g[i][j] = std::max(l[i][j], g[i - 1][j]);
        }
    }

    return g[len - 1][2];
}

// 解法 2.
// 兩次遍歷
// 第一次正向，取得[0-i]這個區間最大利潤
// 第二次反向，取得[i-n]這個區間最大利潤
// 最後在依序相加並且取最大值
// 區間最大利潤算法如同 121.
// 只不過反向時須倒過來想
// o(n) three pass.
int maxProfit(std::vector<int>& prices) {
    if (prices.size() < 2) return 0;

    int len = prices.size();
    std::vector<int> right(len);
    std::vector<int> left(len);
    
    // 正向
    left[0] = 0;
    int mn = prices[0];
    for (int i = 1; i < len; i++) {
        mn = std::min(mn, prices[i]);
        left[i] = std::max(left[i - 1], prices[i] - mn);
    }

    // 反向
    right[len - 1] = 0;
    int mx = prices[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        mx = std::max(mx, prices[i]);
        right[i] = std::max(right[i + 1], mx - prices[i]);
    }

    int profit = 0;
    for (int i = 0; i < len; i++) {
        profit = std::max(right[i] + left[i], profit);
    }

    return profit;
}

// 解法 3.
// 最佳解 O(n) one pase, O(1) space
// 非常碉堡
int maxProfit(std::vector<int>& prices) {
    if (prices.size() < 2) return 0;

    int buy_1 = INT_MIN, buy_2 = INT_MIN;
    int sell_1 = 0, sell_2 = 0;

    for (auto& n : prices) {
        buy_1 = std::max(buy_1, -n); // 一開始沒錢，所以借錢，此時手上有的錢為 -n
        sell_1 = std::max(sell_1, buy_1 + n); // 第一次賣出，手上的前加上股價，為了最大利潤所以取 max

        buy_2 = std::max(buy_2, sell_1 - n); // 第二次買入，手上的錢有 sell_2，為了剩下最多錢，取 max 決定要不要買
        sell_2 = std::max(sell_2, buy_2 + n); // 第二次賣出，手上有 buy_2 的錢，賣出 n 所以最後為 buy_2 + n，為了最大利潤所以取 max
    }

    return sell_2;
}