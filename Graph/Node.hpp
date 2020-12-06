#pragma once

#include <iostream>
#include <list>
// #include "Edge.hpp"

namespace Graph {
  class Edge;
  class Node {
  public:
    int id;
    int val;
    std::list<Node*> nexts;
    std::list<Edge*> edges;
    int in;
    int out;
  public:
    Node(int rid, int a) {
      id = rid;
      val = a;
      in = 0;
      out = 0;
    }
    Node(int rid) {
      id = rid;
      val = 0;
      in = 0;
      out = 0;
    }

    bool operator==(const Node& a) {
      return this == &a;
    }

    ~Node() {
//      while (!edges.empty()) {
//        auto& e = edges.front();
//        edges.pop_front();
//        if (e) {
//          delete e;
//          e = nullptr;
//        }
//      }
//      for (auto n : nexts) {
//        if (n->in <= 0) {
//          delete n;
//        }
//      }
    }
  };



};