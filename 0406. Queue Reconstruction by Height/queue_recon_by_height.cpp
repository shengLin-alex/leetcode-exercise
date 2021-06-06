// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k),
// where h is the height of the person and k is the number of people in front of this person who have a height greater
// than or equal to h. Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
  // 從高排到矮
  // 如果一樣高，第二個數字小的排前面
  sort(people.begin(), people.end(),
       [](vector<int> a, vector<int> b) { return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); });

  vector<vector<int>> res;
  for (auto p : people) {
    res.insert(res.begin() + p[1], p); // 根據排序後的列隊第二個數字來插入新的列隊
  }

  return res;
}

int main() {
  vector<vector<int>> t = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

  auto res = reconstructQueue(t);

  return 0;
}