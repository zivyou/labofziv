#include <chrono>
#include <iostream>
#include <climits>
#include <unordered_set>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

class Edge {
public:
    int from;
    int to;
    Edge(int a, int b):from(a),to(b){}
    bool operator==(const Edge& a) const {
        return a.from == from && a.to == to;
    }
};

struct EdgeHash {
    size_t operator()(const Edge& edge) const {
        return edge.from^edge.to;
    }
};

// bfs, 按层遍历
class Solution3 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> > & edges) {
        if (n == 0)
            return {};
        if (n == 1){
            return {0};
        }
        vector<vector<int>> neighbors;
        int rank[n+1];
        for (int i=0; i<=n; i++) {
            neighbors.push_back({});
            rank[i] = 0;
        }
        for (const auto& v : edges) {
            auto from = v[0]; auto to = v[1];
            neighbors[from].push_back(to);
            neighbors[to].push_back(from);
            rank[from]++; rank[to]++;
        }

        queue<int> leaves;
        for (int i=0; i<=n; i++) {
            if (rank[i] == 1) leaves.push(i);
        }
        queue<int> result;
        while (!leaves.empty()) {
            result = leaves;
            auto amount = leaves.size();
            // printf("leaves amount: %ld\n", amount);
            for (auto i=0; i<amount; i++) {
                auto leaf = leaves.front();
                leaves.pop();
                for (const auto& x : neighbors[leaf]) {
                    // printf("leaf: %d, neighbors: %d\n", leaf, x);
                    rank[x]--;
                    rank[leaf]--;
                    if (rank[x] == 1) {
                        leaves.push(x);
                    }
                }
            }
        }
        vector<int> r;
        while (!result.empty()) {
            r.push_back(result.front());
            result.pop();
        }
        return r;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> > & edges) {
        if (n == 0)
            return {};
        if (n == 1){
            return {0};
        }
        int rank[n+1];
        fill_n(rank, n+1, 0);
        unordered_set<Edge, EdgeHash> edgeSet;
        unordered_set<int> nodes;
        for (const auto& v : edges) {
            edgeSet.insert(Edge(v[0], v[1]));
            nodes.insert(v[0]); nodes.insert(v[1]);
            rank[v[0]]++;
            rank[v[1]]++;
        }
        while (!edgeSet.empty()) {
            unordered_set<int> leaves;
            unordered_set<Edge, EdgeHash> toBeDeletedEdges;
            for (const auto& e : edgeSet) {
                if (rank[e.from] == 1 && rank[e.to] > 1) {
                    leaves.insert(e.from);
                    toBeDeletedEdges.insert(e);
                }
                if (rank[e.to] == 1 && rank[e.from] > 1) {
                    leaves.insert(e.to);
                    toBeDeletedEdges.insert(e);
                }
            }
            if (leaves.empty()) break;
            else {
                for (const auto& n : leaves) {
                    nodes.erase(n);
                }
                for (const auto & e : toBeDeletedEdges) {
                    edgeSet.erase(e);

                    rank[e.from]--;
                    rank[e.to]--;
                }
            }
        }
        return {nodes.begin(), nodes.end()};
    }
};

class Solution2 {
private:
    int** graph;
    void init(int n) {
        graph = new int*[n+1];
        for (int i=0; i<n+1; i++) {
            graph[i] = new int[n+1];
            fill_n(graph[i], n+1, n+2);
        }
    }

    void destroy(int n) {
        for (int i=0; i<n+1; i++) {
            delete[] graph[i];
        }
        delete[] graph;
    }
    void floyd(int n) {
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n && graph[i][k]<=n && graph[k][j]<=n; j++) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k]+graph[k][j]);
                    graph[j][i] = graph[i][j];
                }
            }
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        init(n);
        for (const auto& edge : edges) {
            auto x = edge[0];
            auto y = edge[1];
            graph[x][y] = 1;
            graph[y][x] = 1;
            graph[x][x] = 0;
            graph[y][y] = 0;
        }
        floyd(n);
        vector<int> results; map<int, int> m;
        for (int i=0; i<n; i++) {
            int max = INT_MIN;
            for (int j=0; j<n; j++) {
                // printf("%d -> %d is %d \n", i, j, graph[i][j]);
                if (graph[i][j] > max) {
                    max = graph[i][j];
                }
            }
            m[i] = max;
        }
        int min = INT_MAX;
        for (const auto& x : m) {
            // printf("%d : %d \n", x.first, x.second);
            if (x.second < min) {
                min = x.second;
            }
        }
        for (const auto& x : m) {
            if (x.second == min) {
                results.push_back(x.first);
            }
        }
        destroy(n);
        return results;
    }
};




int main(){
    int n;
    vector<vector<int>> data;
    FILE* file = fopen("/home/youziqi/Documents/workspace/labofziv/leetcode-cn-cpp/input-leetcode-cn-310.txt", "r");
    std::fscanf(file, "%d\n", &n);
    std::fscanf(file, "[");
    int a, b, count;
    while ((count = std::fscanf(file, "[%d,%d],", &a, &b)) != EOF && count > 0) {
        data.push_back({a, b});
    }

    auto start = chrono::system_clock::now();
    Solution3 s;
    vector<int> v = s.findMinHeightTrees(n, data);
    for (auto num : v){
        cout<<num<<" ";
    }
    cout<<endl;
    auto end = chrono::system_clock::now();
    printf("findMinHeightTrees spent: %f s\n", ((chrono::duration<double>)(end-start)).count());
    fclose(file);
    return 0;
}