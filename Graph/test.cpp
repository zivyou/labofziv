#include <vector>
#include "Graph.hpp"

using namespace std;
int main(int argc, char* argv[]) {
  vector<vector<int> > matrix = {{7, 0, 1}, {3, 1, 2}, {5, 0, 2}};
  Graph::Graph* graph = Graph::Graph::LoadFromMatrix(matrix);
  graph->display();
  graph->bfs(1);
  delete graph;
  return 0;
}