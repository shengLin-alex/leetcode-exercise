// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#include <algorithm>
#include <vector>

// 區間重疊的特性
// 1...5
//  2...6
// => 1....6
// 先對第一個數字由小到大排序
// 再從第二個區間開始檢查該區間第二個數字與前一個區間第一個數字之否重疊
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
  if (intervals.empty())
    return {};
  auto comp = [](std::vector<int> a, std::vector<int> b) { return a[0] < b[0]; };
  std::sort(intervals.begin(), intervals.end(), comp);

  std::vector<std::vector<int>> res = {intervals[0]};

  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] <= res.back()[1]) {
      // 有重疊，則區間第二個數字要取自己第二個數字與目前遍歷之區間第二個數字較大者
      res.back()[1] = std::max(res.back()[1], intervals[i][1]);
    } else {
      res.push_back(intervals[i]);
    }
  }

  return res;
}