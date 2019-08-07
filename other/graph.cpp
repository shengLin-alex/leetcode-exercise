#include <iostream>
#include <list>
#include <queue>
#include <vector>

// adj list implement
class Graph {
public:
  Graph() : _num_vertex(0){};
  Graph(int N) : _num_vertex(N) {
    this->_adjList.resize(this->_num_vertex);
  };
  ~Graph() {
    if (this->_color)
      delete[] this->_color;

    if (this->_distance)
      delete[] this->_distance;

    if (this->_discover)
      delete[] this->_discover;

    if (this->_predecessor)
      delete[] this->_predecessor;

    if (this->_finish)
      delete[] this->_finish;
  }
  void addEdgeList(int from, int to);
  void bfs(int start);
  void dfs(int start);
  void print();

private:
  int _num_vertex;
  std::vector<std::list<int>> _adjList;
  int *_color = nullptr,       // 0: while, 1: gray, 2: black
      *_predecessor = nullptr, // -1: no predecessor, as a start vertex

          /* member for bfs */
          *_distance = nullptr, // 0: start, max: the vertex cannot reach from start

              /* member for dfs */
              *_discover = nullptr,   // storage discover time
                  *_finish = nullptr; // storage finish time

  void dfsVisit(int vertex, int &time);
};

void Graph::addEdgeList(int from, int to) {
  this->_adjList[from].push_back(to);
}

void Graph::bfs(int start) {
  this->_color = new int[this->_num_vertex];
  this->_predecessor = new int[this->_num_vertex];
  this->_distance = new int[this->_num_vertex];

  for (int i = 0; i < this->_num_vertex; i++) { // init
    this->_color[i] = 0;                        // 0: white
    this->_predecessor[i] = -1;                 // -1: no predecessor
    this->_distance[i] = this->_num_vertex + 1; // the maxg distance
  }

  std::queue<int> qu;
  int i = start;

  for (int j = 0; i < this->_num_vertex; j++) { // use for loop make sure traversal all vertex
    if (this->_color[i] == 0) {                 // check visited
      this->_color[i] = 1;                      // set visited
      this->_distance[i] = 0;
      this->_predecessor[i] = -1;
      qu.push(i);
      while (!qu.empty()) {
        int new_start = qu.front();                       // get new start
        for (const auto &v : this->_adjList[new_start]) { // search vertex from new start
          if (this->_color[v] == 0) {
            this->_color[v] = 1;
            this->_distance[v] = this->_distance[new_start] + 1;
            this->_predecessor[v] = new_start;
            qu.push(v);
          }
        }
        qu.pop();
        this->_color[new_start] = 2;
      }
    }
    i = j; // cannot traversal all vertex at one time, set i = j make sure traversal all vertex
  }
}

void Graph::dfs(int start) {
  this->_color = new int[this->_num_vertex];
  this->_discover = new int[this->_num_vertex];
  this->_finish = new int[this->_num_vertex];
  this->_predecessor = new int[this->_num_vertex];

  int time = 0;
  for (int i = 0; i < this->_num_vertex; i++) { // init
    this->_color[i] = 0;
    this->_discover[i] = 0;
    this->_finish[i] = 0;
    this->_predecessor[i] = -1;
  }

  int i = start;
  for (int j = 0; j < this->_num_vertex; j++) { // make sure all vertex have been searched
    if (this->_color[i] == 0) {
      this->dfsVisit(i, time);
    }

    i = j;
  }
}

void Graph::dfsVisit(int vertex, int &time) {
  this->_color[vertex] = 1;         // set gray
  this->_discover[vertex] = ++time; // update discover time
  for (const auto &v : this->_adjList[vertex]) {
    if (this->_color[v] == 0) {       // iterate all vertex that connected and check if is discover
      this->_predecessor[v] = vertex; // set predecessor
      this->dfsVisit(v, time);        // set as new start and visit
    }
  }

  this->_color[vertex] = 2;       // after visit all connected vertex, set finish color
  this->_finish[vertex] = ++time; // update finish time
}

void Graph::print() {
  if (this->_color) {
    std::cout << "color: " << std::endl;
    for (int i = 0; i < this->_num_vertex; i++) {
      std::cout << this->_color[i] << ",";
    }
    std::cout << std::endl;
  }

  if (this->_distance) {
    std::cout << "distance: " << std::endl;
    for (int i = 0; i < this->_num_vertex; i++) {
      std::cout << this->_distance[i] << ",";
    }
    std::cout << std::endl;
  }

  if (this->_predecessor) {
    std::cout << "predecessor: " << std::endl;
    for (int i = 0; i < this->_num_vertex; i++) {
      std::cout << this->_predecessor[i] << ",";
    }
    std::cout << std::endl;
  }

  if (this->_discover) {
    std::cout << "_discover: " << std::endl;
    for (int i = 0; i < this->_num_vertex; i++) {
      std::cout << this->_discover[i] << ",";
    }
    std::cout << std::endl;
  }

  if (this->_finish) {
    std::cout << "_finish: " << std::endl;
    for (int i = 0; i < this->_num_vertex; i++) {
      std::cout << this->_finish[i] << ",";
    }
    std::cout << std::endl;
  }
}

int main() {
  Graph g1(9);
  g1.addEdgeList(0, 1);
  g1.addEdgeList(0, 2);
  g1.addEdgeList(0, 3);
  g1.addEdgeList(1, 0);
  g1.addEdgeList(1, 4);
  g1.addEdgeList(2, 0);
  g1.addEdgeList(2, 4);
  g1.addEdgeList(2, 5);
  g1.addEdgeList(2, 6);
  g1.addEdgeList(2, 7);
  g1.addEdgeList(3, 0);
  g1.addEdgeList(3, 7);
  g1.addEdgeList(4, 1);
  g1.addEdgeList(4, 2);
  g1.addEdgeList(4, 5);
  g1.addEdgeList(5, 2);
  g1.addEdgeList(5, 4);
  g1.addEdgeList(5, 8);
  g1.addEdgeList(6, 2);
  g1.addEdgeList(6, 7);
  g1.addEdgeList(6, 8);
  g1.addEdgeList(7, 2);
  g1.addEdgeList(7, 3);
  g1.addEdgeList(7, 6);
  g1.addEdgeList(8, 5);
  g1.addEdgeList(8, 6);

  g1.bfs(0);

  std::cout << "g1 bfs =>" << std::endl;
  g1.print();

  std::cout << std::endl;

  Graph g2(8);
  g2.addEdgeList(0, 1);
  g2.addEdgeList(0, 2);
  g2.addEdgeList(1, 3);
  g2.addEdgeList(2, 1);
  g2.addEdgeList(2, 5);
  g2.addEdgeList(3, 4);
  g2.addEdgeList(3, 5);
  // AdjList[4] is empty
  g2.addEdgeList(5, 1);
  g2.addEdgeList(6, 4);
  g2.addEdgeList(6, 7);
  g2.addEdgeList(7, 6);

  g2.dfs(0);

  std::cout << "g2 dfs =>" << std::endl;
  g2.print();

  return 0;
}