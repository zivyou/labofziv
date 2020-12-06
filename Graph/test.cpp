#include <vector>
#include "Graph.hpp"

using namespace std;
int main(int argc, char* argv[]) {
  vector<vector<int> > matrix = {{1, 3}, {2, 0}};
  Graph::Graph* graph = Graph::Graph::LoadFromMatrix(matrix);
  graph->display();
  delete graph;
  return 0;
}