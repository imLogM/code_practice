//实现一个基本的计算器来计算一个简单的字符串表达式的值。
//
//字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
//
//示例 1:
//
//输入: "3+2*2"
//输出: 7
//示例 2:
//
//输入: " 3/2 "
//输出: 1
//示例 3:
//
//输入: " 3+5 / 2 "
//输出: 5
//说明：
//
//你可以假设所给定的表达式都是有效的。
//请不要使用内置的库函数 eval。

class Solution {
public:
    int calculate(string s) {
        // 遇到+，将下一个数num入栈；遇到-，则将-num入栈；遇到乘或除，先将上一个数出栈，与当前数进行运算后，再将结果入栈。读取完整个字符串后，将栈中所有的数相加即运算结果。
        int len = s.size();
        if (len==0) { return 0; }

        int num = 0;
        char sign = '+';
        stack<int> stacks;
        for (int i=0; i<len; ++i) {
            if (s[i]>='0' && s[i]<='9') {
                num = num*10 + (s[i]-'0');
            } else if (s[i] == ' ') {
                // num = 0;
            }
            if ( (!(s[i]>='0' && s[i]<='9') && s[i] != ' ') || i==len-1) {
                if (sign == '+') {
                    stacks.push(num);
                    // printf("+%d, ", num);
                } else if (sign == '-') {
                    stacks.push(-1*num);
                    // printf("-%d, ", num);
                } else if (sign == '*') {
                    int a = stacks.top();
                    stacks.pop();
                    stacks.push(a*num);
                    // printf("*%d, %d", num, a*num);
                } else if (sign == '/') {
                    int a = stacks.top();
                    stacks.pop();
                    stacks.push(a/num);
                    // printf("/%d, %d", num, a/num);
                }
                num = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!stacks.empty()) {
            res += stacks.top();
            stacks.pop();
        }
        return res;
    }
};