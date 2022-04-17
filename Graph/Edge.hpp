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
    int fromId;
    int toId;

  public:
    Edge(int w, Node*& f, Node*& t) {
      weight = w;
      from = f;
      to = t;
      fromId = from->id;
      toId = to->id;
    }
    Edge() {
      weight = -1;
      from = nullptr;
      to = nullptr;
      fromId = -1;
      toId = -1;
    };

    ~Edge() {
      delete from;
      delete to;
    };
  };
}
