//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
//示例 1:
//
//输入:
//[
//[ 1, 2, 3 ],
//[ 4, 5, 6 ],
//[ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
//示例 2:
//
//输入:
//[
//[1, 2, 3, 4],
//[5, 6, 7, 8],
//[9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    void printCircle(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>& results) {
        // 行
        if (y1>y2) { return; }
        for (int j=y1; j<=y2; ++j) {
            results.push_back(matrix[x1][j]);
        }
        // 列
        if (x1+1>x2) { return; }
        for (int i=x1+1; i<=x2; ++i) {
            results.push_back(matrix[i][y2]);
        }
        // 行
        if (y1>y2-1) { return; }
        for (int j=y2-1; j>=y1; --j) {
            results.push_back(matrix[x2][j]);
        }
        // 列
        if (x1+1>x2-1) { return; }
        for (int i=x2-1; i>=x1+1; --i) {
            results.push_back(matrix[i][y1]);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        int rows = (int)matrix.size();
        if (rows <= 0 ) { return results; }
        int cols = (int)matrix[0].size();
        if (cols <= 0) { return results; }

        int x1 = 0, y1 = 0, x2 = rows-1, y2 = cols-1;
        while (x2>=x1 && y2>=y1) {
            printCircle(matrix, x1, y1, x2, y2, results);
            ++x1; --x2;
            ++y1; --y2;
        }

        return results;
    }
};


