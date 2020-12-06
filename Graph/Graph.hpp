#include <unordered_map>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Node.hpp"
#include "Edge.hpp"

namespace Graph {
  using namespace std;

  class Graph {
  private:
    std::unordered_map<Node*, bool> nodes;
    std::unordered_map<Edge *, bool> edges;
  public:
    Graph() {};
    void addNode(Node* n) {
      if (nodes.find(n) == nodes.end()) {
        nodes[n] = true;
      }
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
      e->from->out++;e->to->in++;
      if (nodes.find((e->from)) == nodes.end()) {
        nodes[(e->from)] = true;
        e->from->nexts.push_back(e->to);
        e->from->edges.push_back(e);
      }
      if (nodes.find((e->to)) == nodes.end()) {
        nodes[(e->to)] = true;
      }
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
        if (n.second && n.first->in <= 0) {
          delete n.first;
          n.second = false;
        }
      }
    };
  };
};