#include <vector>
#include <unordered_set>
#include "Graph.hpp"


using namespace std;
int main() {
  Graph::Graph* graph = Graph::Graph::build1();
  graph->display();
  
  std::unordered_set<const Graph::Edge*> tree = graph->prim();
  std::cout<<"tree size:"<<tree.size()<<std::endl;
  for (auto e : tree) {
    std::cout<<e->fromId<<" -> "<<e->toId<<", "<<e->from<<" => "<<e->to<<endl;
  }
  delete graph;
  return 0;
}
//int main(int argc, char* argv[]) {
//  vector<vector<int> > matrix = {{0, 1, 1}, {0, 0, 1}, {0, 0, 0}};
//  Graph::Graph* graph = Graph::Graph::LoadFromMatrix(matrix);
//  graph->display();
//  graph->bfs(0);
//  graph->dfs(0);
//  std::vector<int> result = graph->topologySort();
//  for (auto n : result) {
//    std::cout<<n<<", ";
//  }
//  std::cout<<std::endl;
//  delete graph;
//  return 0;
//}
