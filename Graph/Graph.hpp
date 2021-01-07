#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <map>
#include <fstream>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include "Node.hpp"
#include "Edge.hpp"
#include "UnionFindSet.h"

namespace Graph {
  using namespace std;

  class Graph {
  private:
    std::unordered_map<Edge *, bool> edges;
    std::map<int, Node*> nodes;
  public:
    Graph() {};
    void addNode(Node* n) {
      if (nodes.find(n->id) == nodes.end()) {
        nodes[n->id] = n;
      }
    }

    std::vector<int> topologySort() {
      std::map<int, int> backup;
      for (auto& elem : nodes) {
        backup[elem.first] = elem.second->in;
      }

      std::list<int>  zeroIn;
      for (auto& elem : nodes) {
        if (elem.second->in == 0) {
          zeroIn.push_back(elem.first);
        }
      }

      std::vector<int> result;
      while (!zeroIn.empty()) {
        int n = zeroIn.front();
        zeroIn.pop_front();
        result.push_back(n);
        Node* node = nodes[n];
        for (auto& e : node->nexts) {
          nodes[e]->in--;
          if (nodes[e]->in <= 0) zeroIn.push_back(e);
        }
      }

      // recover
      for (auto &e : nodes) {
        e.second->in = backup[e.first];
      }
      return result;
    }

    void bfs(int startId) {
      std::cout<<"before bfs...."<<std::endl;
      std::queue<Node*> st;
      std::set<int> visited;
      Node* start = nodes[startId];
      st.push(start);
      while (!st.empty()) {
        Node* n = st.front();
        st.pop();
        if (visited.find(n->id) == visited.end()) {
          std::cout<<"bfs visit:"<<n->id<<std::endl;
          visited.insert(n->id);
          for (auto next : n->nexts) {
            if (visited.find(next) == visited.end()) {
              st.push(nodes[next]);
            }
          }
        }
      }
    }

    void dfs(int startId) {
      std::cout<<"before dfs..."<<std::endl;
      std::stack<Node*> st;
      std::set<int> visited;
      st.push(nodes[startId]);
      while (!st.empty()) {
        Node* n = st.top();
        st.pop();
        std::cout<<"visiting node"<<n->id<<"...";
        visited.insert(n->id);
        for (auto x : n->nexts) {
          if (visited.find(x) == visited.end()) {
            st.push(nodes[x]);
            break;
          }
        }
      }
      std::cout<<std::endl;
    }
   
    class EdgeCompare {
      bool reverse;
    public:
      EdgeCompare(const bool& revparam=false) {
        reverse = revparam;
      }

      bool operator()(const Edge*& lhs, const Edge*& rhs) const {
        if (reverse) return lhs->weight > rhs->weight;
        else return lhs->weight < rhs->weight;
      }
    };

    // k算法，暂未测试2021/01/06
    // 不断的选最小的边，如果最小边的两个端点不再一个集合，则是目标边，并合并两个端点所在的集合
    std::unordered_set<const Edge*> kruskal() {
      std::priority_queue<const Edge*, std::vector<const Edge*>, Graph::EdgeCompare> pq(EdgeCompare(false)); 
      for (auto e: edges) {
        pq.push(e.first);
      }
      std::unordered_set<const Edge*> result;
      UnionFindSet ufs(nodes.size());
      while (!pq.empty()) {
        const Edge* edge = pq.top();
        pq.pop();
        if (ufs.Find(edge->from->id) != ufs.Find(edge->to->id)) {
          result.insert(edge);
          ufs.Union(edge->from->id, edge->to->id);
        }
      }
      return result;
    }

    
    // prim算法，暂未测试过。2020/01/06
    // 先选一个点，再选出这个点关联的最小边，放入待选边集合中。遍历待选边集合，选最小的那条边，如果边那头的点没有访问过，这个边就是目标边。
    std::unordered_set<const Edge*> prim() {
      std::priority_queue<const Edge*, std::vector<const Edge*>, Graph::EdgeCompare> pq(EdgeCompare(false));
      std::unordered_set<const Edge*> result;
      std::unordered_set<Node*> visitedNodes;
      std::vector<Node*> allNodes;
      for (auto n: nodes) {
        allNodes.push_back(n.second);
      }
      visitedNodes.insert(allNodes[0]);
      for (auto e: allNodes[0]->edges) {
        pq.push(e); 
      }
      while (!pq.empty()) {
        const Edge* e = pq.top();
        pq.pop();
        if (visitedNodes.find(e->to) != visitedNodes.end()) {
          // 这条边的那头的点没有被访问过
          visitedNodes.insert(e->to);
          result.insert(e);
          for (auto ne : e->to->edges) {
            pq.push(ne);
          }
        }
      }
      return result;
    }

    void display() {
      ofstream dotFile;
      try {
        dotFile.open("./graph.dot", ios::out);
        dotFile<<"digraph {"<<std::endl;
        for (auto& e: edges) {
          dotFile<<e.first->from->id<<" -> "<<e.first->to->id<<";"<<std::endl;
        }
        dotFile<<"}";
      } catch (exception& e) {
        std::cout<<"file rw error when graph display:"<<e.what()<<std::endl;
        return;
      }
    }

    void addNode(Edge*& e) {
      if (nodes.find((e->fromId)) == nodes.end()) {
        nodes[(e->fromId)] = e->from;
      }
      if (nodes.find((e->toId)) == nodes.end()) {
        nodes[(e->toId)] = e->to;
      }
      Node* from = nodes[e->fromId];
      Node* to = nodes[e->toId];
      from->out++;to->in++;
      from->nexts.push_back(e->toId);
      from->edges.push_back(e);
    }

    void addEdge(Edge*& e) {
      if (edges.find(e) == edges.end()) {
        edges[e] = true;
        addNode(e);
      }
    }

    static Graph* LoadFromMatrix(std::vector<std::vector<int> > matrix) {
      int x = matrix.size();
      if (x <= 1) return new Graph();
      int y = matrix[0].size();
      Graph* graph = new Graph();
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
          if (matrix[i][j] > 0) {
            Node* ni = new Node(i);
            Node* nj = nullptr;

            if (i == j) {
              nj = ni;
            } else nj = new Node(j);
            Edge* e = new Edge(matrix[i][j], ni, nj);
            graph->addEdge(e);
          }
        }
      }

      return graph;
    }

    ~Graph() {
      for (auto e : edges) {
        if (e.second) {
          e.first->to->in--;
          e.first->from->out--;
          delete e.first;
          e.second = false;
        }
      }
      for (auto& n : nodes) {
        if (n.second && n.second->in <= 0) {
          delete n.second;
        }
      }
    };
  };
};
