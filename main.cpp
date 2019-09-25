#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
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
            // 加这个字符
            getValid(s, results, result, index+1);
            // 不加这个字符
            result += s[index];
            getValid(s, results, result, index+1);
            result.pop_back();
        } else {
            //普通字符直接加
            result += s[index];
            getValid(s, results, result, index+1);
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
int main()
{
    Solution so;
    so.removeInvalidParentheses("(a)())()");
    return 0;
}