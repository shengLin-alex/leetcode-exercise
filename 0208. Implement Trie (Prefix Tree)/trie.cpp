// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

#include <string>

class TrieNode {
public:
  TrieNode *child[26];
  bool isWord;
  TrieNode() : isWord(false) {
    for (auto &a : child)
      a = nullptr;
  }
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() : root(new TrieNode()) {}

  /** Inserts a word into the trie. */
  void insert(std::string word) {
    TrieNode *p = this->root;
    // 遍歷 keyword 並且取每一個字符在字母表中位置
    // 接著從 root child 開始 access 直到沒有儲存節點的位置並塞入新的節點
    for (auto &c : word) {
      int idx = c - 'a';
      if (p->child[idx] == nullptr)
        p->child[idx] = new TrieNode();

      p = p->child[idx];
    }
    p->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(std::string word) {
    TrieNode *p = this->root;

    for (auto &c : word) {
      int idx = c - 'a';
      if (p->child[idx] == nullptr)
        return false;

      p = p->child[idx];
    }

    return p->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(std::string prefix) {
    TrieNode *p = this->root;
    for (auto &c : prefix) {
      int idx = c - 'a';
      if (p->child[idx] == nullptr)
        return false;

      p = p->child[idx];
    }

    return true;
  }

private:
  TrieNode *root;
};
