//统计所有小于非负整数 n 的质数的数量。
//
//示例:
//
//输入: 10
//输出: 4
//解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

class Solution {
public:
    int countPrimes(int n) {
        if (n==0) { return 0; }
        if (n==1) { return 0; }
        bool* isPrime = new bool[n];
        for (int i=0; i<n; ++i) {
            isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i=0; i<n; ++i) {
            if (isPrime[i]) {
                for (int j=2; i*j<n; ++j) {
                    isPrime[i*j] = false;
                }
            }
        }

        int count = 0;
        for (int i=0; i<n; ++i) {
            if (isPrime[i]) { ++count; }
        }

        delete[] isPrime;

        return count;
    }
};