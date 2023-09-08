#include <cstdio>
#include <limits.h>

using namespace std;

struct Node {
    int k, v;
    Node* next;
    long timestamp;
    Node(int x1, int x2) {
        k = x1; v = x2;
        next = nullptr;
    }
    void update(int n) {
        timestamp = n;
    }
};

class LRUCache {
private:
    Node** nodes;
    int c;
    int count = 0;
    int current = 0;
public:
    LRUCache(int capacity) {
        nodes = new Node*[capacity];
        c = capacity;
        for (int i=0; i<capacity; i++) {
            nodes[i] = new Node(-1, -1);
        }
    }

    // 将p放到链表头
    void resetHead(Node* originHead, Node* p) {
        auto x = originHead;
        while (x->next != p) {
            x = x->next;
        }
        x->next = p->next;
        p->next = originHead->next;
        originHead->next = p;
    }
    // 将p放到链表尾
    void setTail(Node* head, Node* p) {
        auto x = head;
        while (x->next != p) {
            x = x->next;
        }
        x->next = p->next;
        while (x->next) {
            x = x->next;
        }
        x->next = p;
        p->next = nullptr;
    }

    int get(int key) {
        auto index = key % c;
        auto link = nodes[index];
        auto p = link->next;
        while (p) {
            if (p->k == key) {
                p->update(++current);
                setTail(link, p);
                return p->v;
            }
            p = p->next;
        }
        return -1;
    }

    void remove(Node*& head, Node* p) {
        auto x = head;
        while (x && x->next != p) {
            x = x->next;
        }
        x->next = p->next;
        delete p;
        count--;
    }

    void put(int key, int value) {
        auto newNode = new Node(key, value);
        newNode->update(++current);
        auto index = key % c;
        auto p = nodes[index];
        while (p->next) {
            p = p->next;
            if (p->k == key) {
                p->v = value;
                setTail(nodes[index], p);
                p->timestamp = ++current;
                return ;
            }
        }
        count++;
        p->next = newNode;
        newNode->next = nullptr;
        if (count > c) {
            int min = INT_MAX; Node* x;
            for (int i=0; i<c; i++) {
                if (nodes[i]->next && nodes[i]->next->timestamp < min) {
                    x = nodes[i];
                    min = x->next->timestamp;
                }
            }
            remove(x, x->next);
        }
    }
    void debug() {
        printf("[");
        for (int i=0; i<c; i++) {
            if (nodes[i] == nullptr) continue;
            else {
                auto head = nodes[i];
                while (head->next) {
                    printf("{k=%d, v=%d},", head->next->k, head->next->v);
                    head = head->next;
                }

            }
        }
        printf("]\n");
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    int x;
    LRUCache lruCache(2);
    lruCache.put(1, 1);
    lruCache.debug();
    lruCache.put(2, 2);
    lruCache.debug();
    x = lruCache.get(1);
    printf("get: %d\n", x);
    lruCache.put(3,3);
    lruCache.debug();
    x = lruCache.get(2);
    printf("get: %d\n", x);
    lruCache.put(4, 4);
    lruCache.debug();
    x = lruCache.get(1);
    printf("get: %d\n", x);
    x = lruCache.get(3);
    printf("get: %d\n", x);
    x = lruCache.get(4);
    printf("get: %d\n", x);
}