#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TrieNode {
private:
    int pass = 0;
    int end = 0;
    TrieNode* next[26*2] = {nullptr};
    int getIndex(const char& c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        if (c >= 'A' && c <= 'Z') return c - 'A';
        printf("error: un-excepted char: %c\n", c);
        return -1;
    }
public:
    TrieNode() {
        pass = 0; end = 0;
        for (auto& n : next) {
            n = nullptr;
        }
    }
    int getEnd() {
        return this->end;
    }
    int getPass() {
        return this->pass;
    }
    void increasePass() {
        this->pass++;
    }
    void increaseEnd() {
        this->end++;
    }
    bool hasNext(const char& c) {
        int index = getIndex(c);
        if (next[index] != nullptr) return true;
        return false;
    }
    void addNext(const char& c) {
        int index = getIndex(c);
        next[index] = new TrieNode();
    }
    TrieNode* nextOne(const char& c) {
        return next[getIndex(c)];
    }
    ~TrieNode() {
        for (auto& n : next) delete n;
    }
};

class Trie {
private:
    TrieNode* root;
    bool validChar(const char& c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        return false;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
        root = nullptr;
    }
    int addString(const std::string& input) {
        TrieNode* node = root;
        node->increasePass();
        for (const auto& c : input) {
            if (!validChar(c)) return 0;
            if (!node->hasNext(c)) {
                node->addNext(c);
            }
            node = node->nextOne(c);
            node->increasePass();
        }
        node->increaseEnd();
        return 0;
    }
    int search(const std::string& input) {
        if (input.length() <= 0) return 0;
        TrieNode* node = root;
        for (const auto& c : input) {
            if (node->hasNext(c)) {
                node = node->nextOne(c);
            } else {
                return 0;
            }
        }
        return node->getEnd();
    }
    int prefix(const std::string& input) {
        if (input.length() <= 0) return 0;
        TrieNode* node = root;
        for (const auto& c : input) {
            if (node->hasNext(c)) {
                node = node->nextOne(c);
            } else {
                return 0;
            }
        }
        return node->getPass();
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    }
};

int main() {
    printf("welcome to Trie!\n");
    printf("使用方法: 1. 先输入一系列的英文单词，按回车组成我们的词典; "
           "2. 接下来的每一行，都会作为一个输入，输出则是在这个词典中找到了多少次这个单词，"
           "或者有多少个单词以这个输入作为前缀;\n");
    Trie trie;
    printf("====================================================\n");
    printf("请输入一个词典: 每个单词以空格分隔，输入ctrl+d结束输入。\n");
    string input;
    while (cin>>input && !cin.eof()) {
        trie.addString(input);
    }
    cin.clear();
    clearerr(stdin);
    printf("\n请输入你想查询的单词，输入换行结束输入: ");
    cin>>input;
    printf("********************\n"
           "当前词典中有%d个单词以%s作为前缀; \n"
           "当前词典中查询到%d次%s这个单词;\n", trie.prefix(input), input.c_str(), trie.search(input), input.c_str());
    return 0;
}