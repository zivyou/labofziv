#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <unordered_set>

using namespace std;

#define contains(X,e) (X.find(e)!=X.end())

class UnionFindSet {
    unordered_map<string, string> roots;
public:
    string find(string& node) {
        string root = node;
        while (root != roots[root])
            root = roots[root];
        roots[node] = root;
        return root;
    }

    bool doUnion(string &a, string &b) {
        string aRoot = find(a);
        string bRoot = find(b);
        if (aRoot == bRoot) return false;
        roots[b] = aRoot;
        return true;
    }

    void addElem(string& node) {
        if (contains(roots, node)) return;
        roots[node] = node;
    }

};

class Node {
public:
    string& name;
    double value{};
    bool visited{};

    bool operator==(const Node &rhs) const {
        return name == rhs.name;
    }

    bool operator!=(const Node &rhs) const {
        return !(rhs == *this);
    }

    explicit Node(string &name) : name(name) {}
    struct Hasher {
        size_t operator()(const Node& node) const {
            return std::hash<string>()(node.name);
        }
    };
};

class Edge {
public:
    Node& from;
    Node& to;
    double weight;

    bool operator==(const Edge &rhs) const {
        return from == rhs.from &&
               to == rhs.to;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

    Edge(Node &from, Node &to, double weight) : from(from), to(to), weight(weight) {}
    struct Hasher {
        size_t operator()(const Edge& e) const {
            return std::hash<string>()(e.from.name+e.to.name);
        }
    };
};


class Graph {
    unordered_set<Node, Node::Hasher> nodes;
    unordered_set<Edge, Edge::Hasher> edges;

    void addEdge(string& from, string& to, double value) {
        Node a(from);
        Node b(to);
        Edge e(a, b, value);
        if (std::find_if(nodes.begin(), nodes.end(), [&](const auto &item) {
            return item.name == from;
        }) == nodes.end()) {
            nodes.insert(a);
        }
        if (find_if(nodes.begin(), nodes.end(), [&](const auto&item) {
            return item.name == to;
        }) == nodes.end()) {
            nodes.insert(b);
        }
        if (std::find_if(edges.begin(), edges.end(), [&](const auto&item) {
            return item == e;
        }) == edges.end()) {
            edges.insert(e);
        }
    }
};

class Solution {
private:
    ::unordered_map<::string, double> numbers;

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        ::vector<double> result;
        if (equations.empty()) return result;
        UnionFindSet set;
        for (int i=0; i<equations.size(); i++) {
            auto equation = equations[i];
            auto a = equation[0]; auto b = equation[1];
            set.addElem(a);
            set.addElem(b);
            set.doUnion(a, b);
        }



        for (int i=0; i<queries.size(); i++) {
            vector<string> query = queries[i];
            string& a = query[0]; string& b = query[1];
            if (!contains(numbers, a) || !contains(numbers, b)) {
                result.push_back(-1.0);
                continue;
            }
            if (set.find(a) != set.find(b)) {
                result.push_back(-1.0);
                continue;
            }
        }
        return result;
    }

};

int main () {
    Solution s;
    ::vector<::vector<::string>> equations = ::vector<::vector<::string>>({{"a", "b"},{"b", "c"}});
    ::vector<double> values({2.0, 3.0});
    ::vector<::vector<::string>> queries({{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}});
    ::vector<double> result = s.calcEquation(equations, values, queries);
    for (auto e:result) {
        ::cout<<e<<", ";
    }
    ::cout<<::endl;
    return 0;
}