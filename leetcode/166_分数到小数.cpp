//给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
//
//如果小数部分为循环小数，则将循环的部分括在括号内。
//
//示例 1:
//
//输入: numerator = 1, denominator = 2
//输出: "0.5"
//示例 2:
//
//输入: numerator = 2, denominator = 1
//输出: "2"
//示例 3:
//
//输入: numerator = 2, denominator = 3
//输出: "0.(6)"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) { return "inf"; }

        string res;
        long long t, d;
        t = numerator; d = denominator;
        if (t*d<0) {
            res += "-";
        }
        t = abs(t); d = abs(d);

        res += to_string(t/d);
        if (t%d==0) { return res; }

        res += ".";
        unordered_map<int, int> countMap;
        t = t % d;
        while (t!=0) {
            if (countMap.count(t)) {
                res.insert(countMap[t], "(");
                res += ")";
                return res;
            }
            countMap[t] = res.size();
            res += to_string(t*10 / d);
            t = t*10 % d;
        }
        return res;
    }
};
