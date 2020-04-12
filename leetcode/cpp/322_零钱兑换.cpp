//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
//
//示例 1:
//
//输入: coins = [1, 2, 5], amount = 11
//输出: 3
//解释: 11 = 5 + 5 + 1
//示例 2:
//
//输入: coins = [2], amount = 3
//输出: -1
//说明:
//你可以认为每种硬币的数量是无限的。

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount<=0) { return 0; }

        int* dp = new int[amount+1];
        for (int i=0; i<amount+1; ++i) {
            dp[i] = INT_MAX; //初始化为最大值
        }
        dp[0] = 0;

        // 这里不对coin排序也可以
        for (int coin : coins) {
            for (int i=coin; i<=amount; ++i) {
                if (dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i-coin]+1, dp[i]);
                }
            }
        }

        int res = (dp[amount] == INT_MAX)? -1 : dp[amount];
        delete[] dp;
        return res;
    }
};