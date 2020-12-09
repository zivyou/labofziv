#include <vector>
#include "Graph.hpp"

using namespace std;
int main(int argc, char* argv[]) {
  vector<vector<int> > matrix = {{0, 1, 1}, {0, 0, 1}, {0, 0, 0}};
  Graph::Graph* graph = Graph::Graph::LoadFromMatrix(matrix);
  graph->display();
  graph->bfs(0);
  graph->dfs(0);
  std::vector<int> result = graph->topologySort();
  for (auto n : result) {
    std::cout<<n<<", ";
  }
  std::cout<<std::endl;
  delete graph;
  return 0;
}