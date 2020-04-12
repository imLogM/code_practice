//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//        所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//
//说明:
//
//s 可能为空，且只包含从 a-z 的小写字母。
//p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
//示例 1:
//
//输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
//示例 2:
//
//输入:
//s = "aa"
//p = "a*"
//输出: true
//解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//示例 3:
//
//输入:
//s = "ab"
//p = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
//示例 4:
//
//输入:
//s = "aab"
//p = "c*a*b"
//输出: true
//解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
//示例 5:
//
//输入:
//s = "mississippi"
//p = "mis*is*p*."
//输出: false
//

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) {
            return true;
        } else if (p.empty()) {
            return false;
        }

        int i=0, j=0;
        return core(s, p, i, j);
    }
    bool core(string& s, string& p, int i, int j) {
        if (i>=s.size() && j>=p.size()) { return true; }

        if (isStarNext(p, j)) {
            bool ret = core(s, p, i, j+2);
            while (isSame(s, p, i, j)) {
                ret |= core(s, p, i+1, j+2);
                ++i;
            }
            return ret;
        } else {
            if (isSame(s, p, i, j)) {
                return core(s, p, i+1, j+1);
            } else {
                return false;
            }
        }
    }
    bool isSame(string& s, string& p, int i, int j) {
        if (i>=s.size() || j>=p.size() || i<0 || j<0) {
            return false;
        }
        if (p[j]=='.') {
            return true;
        } else {
            if (p[j] == s[i]) {
                return true;
            } else {
                return false;
            }
        }
    }
    bool isStarNext(string& p, int j) {
        if (j+1>=p.size() || j<0) {
            return false;
        }
        return p[j+1] == '*';
    }
};
