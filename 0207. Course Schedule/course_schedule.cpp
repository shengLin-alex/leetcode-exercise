// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed
// as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a
// graph is represented. You may assume that there are no duplicate edges in the input prerequisites.

#include <list>
#include <queue>
#include <vector>

// 題目本質為尋找有向圖的環
// 重點在於如何建立有向圖與如何尋找環

// vertex v
// in-degree 箭頭指向 v 的數
// out-degree 箭頭由 v 指出去的數
bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  // numCourses means numCourses vertex
  std::vector<std::list<int>> graph(numCourses); // adjList for graph represent
  std::vector<int> indegree(numCourses);

  for (auto p : prerequisites) {
    graph[p[1]].push_back(p[0]);
    // indegree[p[0]]++;
  }

  // 往常的取得 indegree 的作法
  // 其實可以在上面的 for loop 就完成
  for (int i = 0; i < numCourses; i++) {
    for (auto in : graph[i])
      indegree[in]++;
  }

  // 利用 bfs 訪問入度為 0 的 vertex
  std::queue<int> qu;
  for (int i = 0; i < numCourses; i++) {
    if (indegree[i] == 0)
      qu.push(i);
  }

  int count = 0;
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for (const auto &v : graph[u]) {
      if (--indegree[v] == 0)
        qu.push(v);
    }

    count++;
  }

  // 如果訪問過的 vertex 數量不等於 graph 的總 vertex表示有環
  return count == numCourses;
}