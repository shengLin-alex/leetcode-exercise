// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and
// sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// Input: [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

#include <climits>
#include <vector>

// 動態規劃：
// buy[i] = max(rest[i - 1] - price[i], buy[i - 1]) buy[i]表示前i天的最後操作是買的最大收益
//              最後是buy -> 與buy[i - 1] 比較取收益較大者

// sell[i] = max(buy[i - 1] + price[i], sell[i - 1]) sell[i]表示前i天的最後操作是賣的最大收益
//              最後是sell -> 與sell[i - 1] 比較取收益較大者

// rest[i] = max(sell[i - 1], buy[i - 1], rest[i - 1]) rest[i]表示前i天的最後操作是cooldown的最大收益

// 由於 rest[i] = sell[i - 1]
// => buy[i] = max(sell[i - 2] - price[i], buy[i - 1])
//    sell[i] = max(buy[i - 1] + price[i], sell[i - 1])

// O(n) time, O(n) space
int maxProfit(std::vector<int> &prices) {
    if (prices.size() == 1)
        return 0;

    std::vector<int> buy(prices.size(), 0);
    std::vector<int> sell(prices.size(), 0);
    buy[0] = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
        sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
        buy[i] = std::max(buy[i - 1], (i > 1 ? sell[i - 2] : 0) - prices[i]);
    }

    return sell.back();
}

// 空間優化
// O(n) time, O(1) space
int maxProfit(std::vector<int> &prices) {
    int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;

    for (int &price : prices) {
        pre_buy = buy;
        buy = std::max(pre_sell - price, pre_buy); // new buy
        pre_sell = sell;
        sell = std::max(pre_buy + price, pre_sell); // new sell
    }

    return sell;
}