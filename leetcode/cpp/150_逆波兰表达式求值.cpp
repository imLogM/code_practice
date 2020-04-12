//根据逆波兰表示法，求表达式的值。
//
//有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//说明：
//
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//示例 1：
//
//输入: ["2", "1", "+", "3", "*"]
//输出: 9
//解释: ((2 + 1) * 3) = 9
//示例 2：
//
//输入: ["4", "13", "5", "/", "+"]
//输出: 6
//解释: (4 + (13 / 5)) = 6
//示例 3：
//
//输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//输出: 22
//解释:
//((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
//

class Solution {
public:
    bool isInt(string token) {
        //判断字符是不是整数
        if (token.empty()) { return false; }
        //负数的情况
        if (token[0] == '-' && token.size()>=2) {
            for (int i=1; i<token.size(); ++i){
                if (token[i]<'0' || token[i]>'9') {
                    return false;
                }
            }
            return true;    // 负数
        }

        //正数的情况
        for (int i=0; i<token.size(); ++i){
            if (token[i]<'0' || token[i]>'9') {
                return false;
            }
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) { return 0; }
        if (tokens.size() == 1 && isInt(tokens[0])) { return stoi(tokens[0]); }

        stack<int> s;
        for (auto ch : tokens) {
            if (isInt(ch)) {
                s.push(stoi(ch));
            } else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (ch == "+") {
                    s.push(a+b);
                } else if (ch == "-") {
                    s.push(b-a);
                } else if (ch == "*") {
                    s.push(a*b);
                } else if (ch == "/") {
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};