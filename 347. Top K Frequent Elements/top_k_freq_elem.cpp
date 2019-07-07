// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    if (nums.size() < 2)
    {
        return nums;
    }

    unordered_map<int, int> bucket;
    vector<int> res;

    for (auto num : nums) bucket[num] += 1;

    for (int j = 0; j < k; j++)
    {
        int max = 0;
        int pos = 0;
        for (auto const &b : bucket)
        {
            if (b.second > max)
            {
                max = b.second;
                pos = b.first;
            }
        }
        bucket[pos] = 0;
        res.push_back(pos);
    }

    return res;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<vector<int>> bucket(n + 1);

    for (auto i : nums)
        mp[i]++;
    for (auto p : mp)
        bucket[p.second].push_back(p.first);

    vector<int> sol;

    for (int i = n; i > 0 && k > sol.size(); --i)
    {
        sol.insert(sol.end(), bucket[i].begin(), bucket[i].end());
    }
    return sol;
}