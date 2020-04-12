//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
//
//示例:
//
//Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");
//trie.search("app");     // 返回 true
//说明:
//
//你可以假设所有的输入都是由小写字母 a-z 构成的。
//保证所有输入均为非空字符串。

class TrieNode {
public:
    bool wordEndFlag;
    TrieNode* child[26];
public:
    TrieNode(){
        wordEndFlag = false;
        for (int i=0; i<26; ++i) {
            child[i] = nullptr;
        }
    }
    ~TrieNode(){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    //这边需要添加析构函数

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tempNode = root;
        for (char ch : word) {
            if (tempNode->child[ch-'a'] == nullptr) {
                tempNode->child[ch-'a'] = new TrieNode();
            }
            tempNode = tempNode->child[ch-'a'];
        }
        tempNode->wordEndFlag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tempNode = root;
        for (char ch : word) {
            if (tempNode->child[ch-'a'] == nullptr) {
                return false;
            } else {
                tempNode = tempNode->child[ch-'a'];
            }
        }
        return tempNode->wordEndFlag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tempNode = root;
        for (char ch : prefix) {
            if (tempNode->child[ch-'a'] == nullptr) {
                return false;
            } else {
                tempNode = tempNode->child[ch-'a'];
            }
        }
        return true;
    }


private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */