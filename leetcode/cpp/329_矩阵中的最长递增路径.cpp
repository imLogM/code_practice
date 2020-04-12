//给定一个整数矩阵，找出最长递增路径的长度。
//
//对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
//
//示例 1:
//
//输入: nums =
//[
//[9,9,4],
//[6,6,8],
//[2,1,1]
//]
//输出: 4
//解释: 最长递增路径为 [1, 2, 6, 9]。
//示例 2:
//
//输入: nums =
//[
//[3,4,5],
//[3,2,6],
//[2,2,1]
//]
//输出: 4
//解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。


class Solution {
public:
    int core(vector<vector<int>>& matrix, int x, int y,
             vector<vector<bool>>& visited, vector<vector<int>>& res) {
        //返回以x,y为起点的最长递增路径
        //visited记录在前面的路径中是否被访问到
        //res为结果矩阵，返回以当前节点为起点的最长递增路径长度
        if (matrix.empty() || matrix[0].empty()) { return 0; }
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (x<0 || x>=rows || y<0 || y>=cols) { return 0; }
        if (visited[x][y] == true) { return res[x][y]; }

        int maxPath = 1;
        if (x+1<rows && matrix[x][y] < matrix[x+1][y]) {
            maxPath = max(core(matrix, x+1, y, visited, res)+1, maxPath);
        }
        if (x-1>=0 && matrix[x][y] < matrix[x-1][y]) {
            maxPath = max(core(matrix, x-1, y, visited, res)+1, maxPath);
        }
        if (y+1<cols && matrix[x][y] < matrix[x][y+1]) {
            maxPath = max(core(matrix, x, y+1, visited, res)+1, maxPath);
        }
        if (y-1>=0 && matrix[x][y] < matrix[x][y-1]) {
            maxPath = max(core(matrix, x, y-1, visited, res)+1, maxPath);
        }
        visited[x][y] = true;
        res[x][y] = maxPath;
        // printf("x=%d, y=%d, res=%d\n", x, y, res[x][y]);

        return maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) { return 0; }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> res(rows, vector<int>(cols, 1));

        for (int x=0; x<rows; ++x){
            for (int y=0; y<cols; ++y) {
                core(matrix, x, y, visited, res);
            }
        }

        //在res矩阵中找最大值
        int result = 0;
        for (auto vec : res) {
            for (auto num : vec) {
                result = max(result, num);
            }
        }
        return result;
    }
};