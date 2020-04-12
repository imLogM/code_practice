//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//例如，给出 n = 3，生成结果为：
//
//[
//"((()))",
//"(()())",
//"(())()",
//"()(())",
//"()()()"
//]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        if (n <= 0) { return results; }

        stack<int> s;
        string result;
        core(n, s, result, results);

        return results;
    }
    void core(int n, stack<int>& s, string& result, vector<string>& results) {
        if (n <= 0 && s.empty()) { results.push_back(result); return ; }


        if (n>0) {
            result.push_back('(');
            s.push(n);
            core(n-1, s, result, results);
            s.pop();
            result.pop_back();
        }
        if (!s.empty()) {
            result.push_back(')');
            int tempNum = s.top();
            s.pop();
            core(n, s, result, results);
            s.push(tempNum);
            result.pop_back();
        }
    }
};
