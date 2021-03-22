#include <iostream>
#include <map>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* myOriginHead = new Node(-1, head, NULL);
        Node* re = new Node(-1, NULL, NULL);
        Node* myNewHead = re;

        map<Node *, Node *> nodesMap;

        Node * n = myOriginHead;
        while (n->next){
            myNewHead->next = new Node(n->next->val, NULL, NULL);
            nodesMap.insert(pair<Node*, Node*>(n->next, myNewHead->next));
            myNewHead = myNewHead->next;
            n = n->next;
        }

        n = myOriginHead;

        myNewHead = re;
        while (n->next){
            if (n->next->random == NULL)
                myNewHead->next->random = NULL;
            else
                myNewHead->next->random  = nodesMap.at(n->next->random);
            myNewHead = myNewHead->next;
            n = n->next;
        }

        return re->next;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
