#include <unordered_map>
#include <vector>
#include <map>
#include <fstream>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include "Node.hpp"
#include "Edge.hpp"

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