//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//
//返回被除数 dividend 除以除数 divisor 得到的商。
//
//示例 1:
//输入: dividend = 10, divisor = 3
//输出: 3
//
//示例 2:
//输入: dividend = 7, divisor = -3
//输出: -2
//说明:
//
//被除数和除数均为 32 位有符号整数。
//除数不为 0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) { return INT_MAX; }
        uint32_t ans=0;
        uint32_t up = (dividend==INT_MIN)? 0x80000000 : (uint32_t)abs(dividend);
        uint32_t down = (divisor==INT_MIN)? 0x80000000 : (uint32_t)abs(divisor);
        while (up >= down) {
            uint32_t count=1, base=down;
            while ((base<0x80000000) &&(up>(base<<1))) {
                count <<= 1;
                base <<= 1;
            }
            ans += count;
            up -= base;
        }

        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (ans<=INT_MAX) { return flag*(int)ans; }
        else if (ans==0x80000000 && flag==-1) { return INT_MIN; }
        else { return INT_MAX; }

    }
};