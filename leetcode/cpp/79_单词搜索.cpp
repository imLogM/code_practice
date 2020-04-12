//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//示例:
//
//board =
//[
//['A','B','C','E'],
//['S','F','C','S'],
//['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true.
//给定 word = "SEE", 返回 true.
//给定 word = "ABCB", 返回 false.
//


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) { return false; }
        if (word.size()<=0) { return true; }

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int x=0; x<rows; ++x) {
            for (int y=0; y<cols; ++y) {
                if (word[0] == board[x][y] && visited[x][y]==false) {
                    visited[x][y] = true;
                    if (core(board, word.substr(1), visited, x, y)) {
                        return true;
                    };
                    visited[x][y] = false;
                }

            }
        }
        return false;
    }
    bool core(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int x, int y) {
        if (word.empty()) { return true; }


        if (x>0 && visited[x-1][y]==false && word[0]==board[x-1][y]) {
            visited[x-1][y] = true;
            if (core(board, word.substr(1), visited, x-1, y)) {
                return true;
            }
            visited[x-1][y] = false;
        }
        if (x<board.size()-1 && visited[x+1][y]==false && word[0]==board[x+1][y]) {
            visited[x+1][y] = true;
            if (core(board, word.substr(1), visited, x+1, y)) {
                return true;
            }
            visited[x+1][y] = false;
        }
        if (y>0 && visited[x][y-1]==false && word[0]==board[x][y-1]) {
            visited[x][y-1] = true;
            if (core(board, word.substr(1), visited, x, y-1)) {
                return true;
            }
            visited[x][y-1] = false;
        }
        if (y<board[0].size()-1 && visited[x][y+1]==false && word[0]==board[x][y+1]) {
            visited[x][y+1] = true;
            if (core(board, word.substr(1), visited, x, y+1)) {
                return true;
            }
            visited[x][y+1] = false;
        }

        return false;

    }
};

