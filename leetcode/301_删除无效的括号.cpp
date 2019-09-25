//删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。
//
//说明: 输入可能包含了除 ( 和 ) 以外的字符。
//
//示例 1:
//
//输入: "()())()"
//输出: ["()()()", "(())()"]
//示例 2:
//
//输入: "(a)())()"
//输出: ["(a)()()", "(a())()"]
//示例 3:
//
//输入: ")("
//输出: [""]
//
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // 暴力回溯
        vector<string> results;
        string result;
        getValid(s, results, result, 0);

        // 找最大长度/最小删除数
        int maxLen = 0;
        for (string str:results) {
            maxLen = max(maxLen, (int)str.size());
        }

        // 找最终结果, 无效输入返回空
        vector<string> ans;
        for (string str:results) {
            if ((int)str.size()==maxLen && find(ans.begin(), ans.end(), str)==ans.end()) {
                ans.push_back(str);
            }
        }
        return ans;
    }

    void getValid(string& s, vector<string>& results, string& result, int index) {
        if (index >= s.size()) {
            if (isValid(result)) {
                results.push_back(result);
            }
            return;
        }

        if (s[index]=='(' || s[index]==')') {
            // 不加这个字符
            getValid(s, results, result, index+1);
            // 加这个字符
            result += s[index];
            getValid(s, results, result, index+1);
            result.pop_back();
        } else {
            //普通字符直接加
            result += s[index];
            getValid(s, results, result, index+1);
            result.pop_back();
        }
    }

    bool isValid(string& s) {
        // 空字符返回true
        int left = 0;
        for (int i=0; i<(int)s.size(); ++i) {
            if (s[i]=='(') {
                ++left;
            } else if (s[i]==')') {
                --left;
                if (left < 0) {
                    return false;
                }
            }
        }
        return left==0;
    }
};
