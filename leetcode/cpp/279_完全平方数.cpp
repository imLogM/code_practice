//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
//
//示例 1:
//
//输入: n = 12
//输出: 3
//解释: 12 = 4 + 4 + 4.
//示例 2:
//
//输入: n = 13
//输出: 2
//解释: 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        if ( n<=0 ) { return 0; }
        //最短路径法
        deque<pair<int, int>> q;
        q.push_back(pair(n, 0));
        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop_front();
            for (int i=(int)sqrt(tmp.first); i>=1; --i) {
                int n_tmp = tmp.first - i*i;
                if (n_tmp == 0) {
                    return tmp.second + 1;
                } else {
                    q.push_back(pair(n_tmp, tmp.second+1));
                }
            }
        }
        return 0;
    }
};