//
//给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
//
//示例 1:
//
//输入:
//[
//[1,1,1],
//[1,0,1],
//[1,1,1]
//]
//输出:
//[
//[1,0,1],
//[0,0,0],
//[1,0,1]
//]
//示例 2:
//
//输入:
//[
//[0,1,2,0],
//[3,4,5,2],
//[1,3,1,5]
//]
//输出:
//[
//[0,0,0,0],
//[0,4,5,0],
//[0,3,1,0]
//]
//进阶:
//
//一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//你能想出一个常数空间的解决方案吗？



class Solution {
public:
    void setRowExZero(vector<vector<int>>& matrix, int row, int num) {
        //把一行内非0的数，设为指定数
        for (int y=0; y<matrix[0].size(); ++y) {
            if (matrix[row][y] != 0) { matrix[row][y]=num; }
        }
    }
    void setColExZero(vector<vector<int>>& matrix, int col, int num) {
        //把一列内非0的数，设为指定数
        for (int x=0; x<matrix.size(); ++x) {
            if (matrix[x][col] != 0) { matrix[x][col]=num; }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        //思路是先把要变为0的位置设成一个特殊数，最后再把特殊数变为0
        if (matrix.empty() || matrix[0].empty()) { return; }

        for (int x=0; x<matrix.size(); ++x) {
            for (int y=0; y<matrix[0].size(); ++y) {
                if (matrix[x][y] == 0) {
                    setRowExZero(matrix, x, INT_MAX-1);
                    setColExZero(matrix, y, INT_MAX-1);
                }
            }
        }
        for (int x=0; x<matrix.size(); ++x) {
            for (int y=0; y<matrix[0].size(); ++y) {
                if (matrix[x][y] == INT_MAX-1) {
                    matrix[x][y] = 0;
                }
            }
        }
    }
};
