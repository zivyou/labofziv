#include <cstdio>
#include <string>

using namespace std;

class Node {
public:
    Node* next[26] = {nullptr};
    int end = 0;
    Node() {
        for (int i=0; i<26; i++) {
            next[i] = nullptr;
        }
    }

    ~Node() {
        for (int i=0; i<26; i++) {
            delete next[i];
        }
    }
};

class WordDictionary {
    Node* root = nullptr;
    int index(const char& c) {
        return c - 'a';
    }
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        auto node = root;
        for (const auto & c : word) {
            if (node->next[index(c)] == nullptr) {
                node->next[index(c)] = new Node();
            }
            node = node->next[index(c)];
        }
        node->end++;
    }

    bool search(const Node* myRoot, const string& word, int wordIndex) {
        auto node = myRoot;
        for (int i=wordIndex; i<word.size(); i++) {
            auto c = word[i];
            if (c != '.') {
                if (node->next[index(c)] != nullptr) {
                    node = node->next[index(c)];
                } else {
                    return false;
                }
            } else {
                for (char cc='a'; cc<='z'; cc++) {
                    if (node->next[index(cc)] != nullptr) {
                        if (search(node->next[index(cc)], word, i+1)) return true;
                    }
                }
                return false;
            }
        }
        return node->end > 0;
    }

    bool search(string word) {
        if (word.empty()) return true;
        return search(root, word, 0);
    }

    ~WordDictionary() {
        delete root;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary dictionary;
    dictionary.addWord("at");
    dictionary.addWord("and");
    dictionary.addWord("an");
    dictionary.addWord("add");
    bool result = dictionary.search("a");
    printf("result : %d\n", result);
}