#include <cstdio>
#include <string>

using namespace std;

class TrieNode {
private:
    TrieNode* nexts[26+1] = {nullptr};
    int p, e;
public:

    TrieNode() {
        for (int i=0; i<26+1; i++) {
            nexts[i] = nullptr;
        }
        p = e = 0;
    }

    ~TrieNode() {
        for (int i=0; i<26+1; i++) {
            delete nexts[i];
        }
    }

    int getIndex(const char& c) {
        return c - 'a';
    }

    bool hasNext(const char& c) {
        if (nexts[getIndex(c)] != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void addNext(const char& c) {
        if (!hasNext(c)) {
            nexts[getIndex(c)] = new TrieNode;
        } else {
            printf("un-excepted add char!\n");
        }
    }

    TrieNode* next(const char& c) {
        return nexts[getIndex(c)];
    }
    void increasePath() {
        p++;
    }
    void increaseEnd() {
        e++;
    }
    int getPath() {
        return p;
    }

    int getEnd() {
        return e;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        root->increasePath();
        auto p = root;
        for (const auto& c : word) {
            if (!p->hasNext(c)) {
                p->addNext(c);
            }
            p = p->next(c);
            p->increasePath();
        }
        p->increaseEnd();
    }

    bool search(string word) {
        auto p = root;
        for (const auto& c : word) {
            if (p->hasNext(c)) {
                p = p->next(c);
            } else {
                return false;
            }
        }
        return p->getEnd() > 0;
    }

    bool startsWith(string prefix) {
        auto p = root;
        for (const auto & c : prefix) {
            if (p->hasNext(c)) {
                p = p->next(c);
            } else {
                return false;
            }
        }
        return p->getPath()>0;
    }

    ~Trie() {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    auto a = trie.search("hello");
    auto b = trie.startsWith("he");
    printf("a=%d, b=%d\n", a,b);
}