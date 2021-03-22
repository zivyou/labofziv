#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    void bfs(Node *origin, Node *clone, map<Node *, Node *> &color){
        if (!origin)
            return;

        queue<Node *> q;
        q.push(origin);
        color.insert(pair<Node *, Node*>(origin, clone));
        while (!q.empty()){
            Node *cur = q.front();
            q.pop();
            Node *curClone = color.find(cur)->second;
            for (int i=0; i<cur->neighbors.size(); i++){
                Node *n = cur->neighbors[i];
                if (color.find(n) == color.end()){
                    q.push(n);
                    Node *nn = new Node(n->val, vector<Node *>());
                    color.insert(pair<Node*, Node*>(n, nn));
                }
                curClone->neighbors.push_back(color.find(n)->second);
            }

        }
    }


    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        Node *cloneNode = new Node(node->val, vector<Node*>());
        //vector<Node *> color;
        map<Node *, Node *> color;
        bfs(node, cloneNode, color);
        return cloneNode;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
