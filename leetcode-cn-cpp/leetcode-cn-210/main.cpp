#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

class Solution {

private:
    int** graph;
    int* ins;
    int nodeCount = 0;

    void buildGraph(const vector<vector<int>>& prerequisites) {
        for (const auto& pair : prerequisites) {
            int a = pair[0];
            int b = pair[1];
            graph[b][a] = 1;
            ins[a]++;
        }
    }

    list<int> getHeadNodes() {
        list<int> result;
        for (int i=0; i<nodeCount; i++) {
            if (ins[i] <= 0) {
                result.push_back(i);
            }
        }
        return result;
    }

    void decreaseIn(int i) {
        ins[i]--;
    }

    bool isZeroIn(int i) {
        return ins[i] == 0;
    }

    vector<int> topoSort() {
        if (nodeCount <= 0) return vector<int>();
        auto heads = getHeadNodes();
        if (heads.empty()) return vector<int>();
        unordered_set<int> visited;
        vector<int> result;
        while (!heads.empty()) {
            auto head = heads.front();
            heads.pop_front();
            if (visited.count(head) > 0) return vector<int>();
            visited.insert(head);
            result.push_back(head);
            for (int next=0; next<nodeCount; next++) {
                if (graph[head][next] > 0) {
                    decreaseIn(next);
                    if (isZeroIn(next)) {
                        heads.push_back(next);
                    }
                }
            }
        }
        if (visited.size() == nodeCount) {
            return result;
        } else return vector<int>();
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        nodeCount = numCourses;
        ins = new int[nodeCount]();
        graph = new int*[nodeCount];
        for (int i=0; i<nodeCount; i++) {
            graph[i] = new int[nodeCount]();
        }
        buildGraph(prerequisites);
        return topoSort();
    }

    ~Solution() {
        for (int i=0; i<nodeCount; i++) {
            delete[] graph[i];
        }
        delete[] ins;
    }
};


int main() {

}