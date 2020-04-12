//给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
//
//示例 1:
//
//输入:
//11110
//11010
//11000
//00000
//
//输出: 1
//示例 2:
//
//输入:
//11000
//11000
//00100
//00011
//
//输出: 3

class Solution {
public:
    //因为dfs有可能在大输入下栈溢出，所以使用bfs
    void bfs(const vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
        if (grid.empty() || grid[0].empty()) { return; }

        int rows = grid.size();
        int cols = grid[0].size();
        if (x<0 || x>=rows || y<0 || y>=cols) { return; }

        if (visited[x][y]) { return; }

        queue< pair<int, int> > q;
        q.push( pair<int, int>(x, y) );
        while (!q.empty()) {
            int tempX = q.front().first;
            int tempY = q.front().second;
            q.pop();

            if (tempX>0 && !visited[tempX-1][tempY] && grid[tempX-1][tempY]=='1') {
                visited[tempX-1][tempY] = true;
                q.push( pair<int, int>(tempX-1, tempY) );
            }
            if (tempY>0 && !visited[tempX][tempY-1] && grid[tempX][tempY-1]=='1') {
                visited[tempX][tempY-1] = true;
                q.push( pair<int, int>(tempX, tempY-1) );
            }
            if (tempX<rows-1 && !visited[tempX+1][tempY] && grid[tempX+1][tempY]=='1') {
                visited[tempX+1][tempY] = true;
                q.push( pair<int, int>(tempX+1, tempY) );
            }
            if (tempY<cols-1 && !visited[tempX][tempY+1] && grid[tempX][tempY+1]=='1') {
                visited[tempX][tempY+1] = true;
                q.push( pair<int, int>(tempX, tempY+1) );
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) { return 0; }

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int num = 0;

        for (int x=0; x<rows; ++x) {
            for (int y=0; y<cols; ++y) {
                if (grid[x][y]=='1' && !visited[x][y]) {
                    ++num;
                    bfs(grid, x, y, visited);
                }
            }
        }

        return num;
    }
};