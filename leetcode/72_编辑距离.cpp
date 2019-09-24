//给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//        删除一个字符
//替换一个字符
//        示例 1:
//
//输入: word1 = "horse", word2 = "ros"
//输出: 3
//解释:
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
//示例 2:
//
//输入: word1 = "intention", word2 = "execution"
//输出: 5
//解释:
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
//
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.size();
        int n2 = (int)word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int x=0; x<=n1; ++x) {
            dp[x][0] = x;
        }
        for (int y=0; y<=n2; ++y) {
            dp[0][y] = y;
        }

        for (int x=1; x<=n1; ++x) {
            for (int y=1; y<=n2; ++y) {
                if (word1[x-1] != word2[y-1]) {
                    dp[x][y] = 1 + min(dp[x-1][y], min(dp[x-1][y-1], dp[x][y-1]));;
                } else {
                    dp[x][y] = dp[x-1][y-1];
                }
            }
        }

        return dp[n1][n2];
    }
};
