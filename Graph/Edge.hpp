#pragma once

#include <list>
#include <memory>
#include "Node.hpp"

namespace Graph{
  class Edge {
  public:
    Node* from;
    Node* to;
    int weight;

  public:
    Edge(int w, Node*& f, Node*& t) {
      weight = w;
      from = f;
      to = t;
    }
    Edge() {
      weight = -1;
      from = nullptr;
      to = nullptr;
    };

    ~Edge() {
    };
  };
}
