// Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be
// planted in adjacent plots - they would compete for water and both would die.

// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a
// number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True
// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False
// Note:
// The input array won't violate no-adjacent-flowers rule.
// The input array size is in the range of [1, 20000].
// n is a non-negative integer which won't exceed the input array size.

#include <vector>

// 解法 1.
// 通過設定連續0的左右邊界來計算連續0可以放幾個 1
// ex. 原始 001
// 由於開頭為 0 沒有邊界因此修正為 : '10'001，1 可以忽略當作默認最左邊是 1 => 0001，最終答案為 (3 - 1) / 2 = 1
// ex. 原始 1000
// => 100001 => 10000 => (4 - 1) / 2 = 1
bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
  if (flowerbed.empty())
    return false;

  if (flowerbed[0] == 0)
    flowerbed.insert(flowerbed.begin(), 0);
  if (flowerbed.back() == 0)
    flowerbed.push_back(0);

  // 利用一個 count 來計算每一次連續0的個數
  int sum = 0, count = 0, len = flowerbed.size();
  for (int i = 0; i <= len; i++) { // 由於可能最後位置一個是 0 因此必須對進入一次迴圈計算
    if (i < len && flowerbed[i] == 0)
      count++;
    else {
      sum += (count - 1) / 2;
      count = 0;
    }
  }

  return sum >= n;
}

// 解法2.
// 透過檢查當前位置為 0 且前後位置也為 0來計算
// 通樣須注意開頭邊界的問題
bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
  for (int i = 0; i < flowerbed.size(); i++) {
    if (n == 0)
      return true;
    if (flowerbed[i] == 0) {
      // 如果最左邊為 0 則邊界假設為 0，否則取當前位置前一位置的值
      int pre = i == 0 ? 0 : flowerbed[i - 1];
      // 如果最右邊為 0 ，則假設邊界為 0 ，否則取當前位置下一位置的值
      int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];

      if (pre + next == 0) { // 前後為 0說明可以放置一盆花
        flowerbed[i] = 1;
        n--;
      }
    }
  }

  return n <= 0;
}