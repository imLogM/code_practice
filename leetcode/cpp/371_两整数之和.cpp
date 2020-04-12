//不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
//
//示例 1:
//
//输入: a = 1, b = 2
//输出: 3
//示例 2:
//
//输入: a = -2, b = 3
//输出: 1

class Solution {
public:
    int getSum(int a, int b) {
        if (a==0) { return b; }
        if (b==0) { return a; }

        // 转换为无符号数，应对负数左移的问题
        unsigned int x = (unsigned int)a^b;
        unsigned int y = ((unsigned int)a&b)<<1;
        return getSum(x, y);
    }
};
