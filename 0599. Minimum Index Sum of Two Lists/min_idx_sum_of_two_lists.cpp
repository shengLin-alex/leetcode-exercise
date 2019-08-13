// Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants
// represented by strings.

// You need to help them find out their common interest with the least list index sum. If there is a choice tie between
// answers, output all of them with no order requirement. You could assume there always exists an answer.

// Example 1:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
// Output: ["Shogun"]
// Explanation: The only restaurant they both like is "Shogun".
// Example 2:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
// Output: ["Shogun"]
// Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
// Note:
// The length of both lists will be in the range of [1, 1000].
// The length of strings in both lists will be in the range of [1, 30].
// The index is starting from 0 to the list length minus 1.
// No duplicates in both lists.

#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

// 利用 hash map 建立 index 與字串的映射
std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2) {
  int min = INT_MAX, n1 = list1.size(), n2 = list2.size();
  std::unordered_map<std::string, int> mp;
  std::vector<std::string> res;
  for (int i = 0; i < n1; i++)
    mp[list1[i]] = i;

  for (int i = 0; i < n2; i++) {
    // 檢查 list2 目前字串是否出現在 list1
    if (mp.count(list2[i]) > 0) {
      int sum = i + mp[list2[i]]; // 取得座標和
      if (sum == min) // 等於最小值則加入 result
        res.push_back(list2[i]);

      if (sum < min) { // 持續更新最小座標和
        min = sum;
        res = {list2[i]};
      }
    }
  }

  return res;
}