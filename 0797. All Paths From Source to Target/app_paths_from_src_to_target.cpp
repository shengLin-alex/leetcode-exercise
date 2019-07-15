// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

// Example:
// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Note:

// The number of nodes in the graph will be in the range [2, 15].
// You can print different paths in any order, but you should keep the order of nodes inside one path.

#include <vector>

void helper(std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &res, std::vector<int> path, int cur) {
    // 將 cursor 加入走過的路徑中
    path.push_back(cur);
    if (cur == graph.size() - 1) res.push_back(path); // 當前 cursor 走到終點時為一組解
    else {
        // 根據 graph 節點前往下一個節點
        for (int p : graph[cur]) helper(graph, res, path, p);
    }
}

std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
    std::vector<std::vector<int>> res;

    // cursor 從 0 開始
    helper(graph, res, {} , 0);

    return res;
}