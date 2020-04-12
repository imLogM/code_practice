//给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
//
//示例 1:
//
//输入: [[1,1],[2,2],[3,3]]
//输出: 3
//解释:
//^
//|
//|        o
//|     o
//|  o
//+------------->
//0  1  2  3  4
//示例 2:
//
//输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出: 4
//解释:
//^
//|
//|  o
//|     o        o
//|        o
//|  o        o
//+------------------->
//0  1  2  3  4  5  6

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int numPoints = points.size();
        printf("num=%d\n", numPoints);
        if (numPoints == 0) { return 0; }
        else if (numPoints == 1) { return 1; }
        else if (numPoints == 2) { return 2; }

        int ans = 2;
        int maxNum = 0;
        for (int i=0; i<numPoints; ++i) {
            for (int j=i+1; j<numPoints; ++j) {
                ans = 2;
                for (int k=0; k<numPoints; ++k) {
                    if (k==i || k==j) { continue; }
                    int x1 = points[i].x;
                    int y1 = points[i].y;
                    int x2 = points[j].x;
                    int y2 = points[j].y;
                    int x3 = points[k].x;
                    int y3 = points[k].y;
                    if (x1==x2 && y1==y2) {
                        if (x1==x3 && y1==y3) {
                            ++ans;
                        }
                        continue;
                    }
                    //斜率的计算变为乘法
                    if ( (int64_t)(x3-x1)*(y2-y1)==(int64_t)(x2-x1)*(y3-y1) ) {
                        ++ans;
                    }
                }
                if (maxNum < ans) { maxNum = ans; }
            }
        }
        return maxNum;
    }
};