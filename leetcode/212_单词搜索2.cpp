//给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
//
//示例:
//
//输入:
//words = ["oath","pea","eat","rain"] and board =
//[
//['o','a','a','n'],
//['e','t','a','e'],
//['i','h','k','r'],
//['i','f','l','v']
//]
//
//输出: ["eat","oath"]
//说明:
//你可以假设所有输入都由小写字母 a-z 组成。
//
//提示:
//
//你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
//如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。
//什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？
//如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

class TireNode{
public:
    string str;
    TireNode* child[26];
public:
    TireNode() {
        str = "";
        for (int i=0; i<26; ++i) {
            child[i] = nullptr;
        }
    }
    ~TireNode() {}
};

class Tire{
public:
    TireNode* root;
public:
    Tire() {
        root = new TireNode();
    }
    bool insert(string s) {
        TireNode* tempNode = root;
        for (char ch : s) {
            if (tempNode->child[ch-'a'] == nullptr) {
                tempNode->child[ch-'a'] = new TireNode();
            }
            tempNode = tempNode->child[ch-'a'];
        }
        tempNode->str = s;
        return true;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, TireNode* root,
             int x, int y, vector<string>& results, vector<vector<bool>>& visited) {
        if (root->str != "") {
            results.push_back(root->str);
            root->str = "";
        }

        int rows = board.size();
        int cols = board[0].size();

        if (x>0 && !visited[x-1][y] && root->child[board[x-1][y]-'a']!=nullptr) {
            visited[x-1][y] = true;
            dfs(board, root->child[board[x-1][y]-'a'], x-1, y, results, visited);
            visited[x-1][y] = false;
        }
        if (x<rows-1 && !visited[x+1][y] && root->child[board[x+1][y]-'a']!=nullptr) {
            visited[x+1][y] = true;
            dfs(board, root->child[board[x+1][y]-'a'], x+1, y, results, visited);
            visited[x+1][y] = false;
        }
        if (y>0 && !visited[x][y-1] && root->child[board[x][y-1]-'a']!=nullptr) {
            visited[x][y-1] = true;
            dfs(board, root->child[board[x][y-1]-'a'], x, y-1, results, visited);
            visited[x][y-1] = false;
        }
        if (y<cols-1 && !visited[x][y+1] && root->child[board[x][y+1]-'a']!=nullptr) {
            visited[x][y+1] = true;
            dfs(board, root->child[board[x][y+1]-'a'], x, y+1, results, visited);
            visited[x][y+1] = false;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;
        if (board.empty() || board[0].empty()) { return results; }

        Tire tireTree;
        for (string word : words) {
            tireTree.insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (tireTree.root->child[board[i][j]-'a'] != nullptr) {
                    visited[i][j] = true;
                    dfs(board, tireTree.root->child[board[i][j]-'a'], i, j, results, visited);
                    visited[i][j] = false;
                }
            }
        }
        return results;
    }
};