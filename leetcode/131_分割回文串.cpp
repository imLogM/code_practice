//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//示例:
//
//输入: "aab"
//输出:
//[
//["aa","b"],
//["a","a","b"]
//]


class Solution {
public:
    bool isPalindrome(const string& s) {
        //判断是否为回文
        if (s.empty()) { return false; }

        for (int i=0; i<s.size(); ++i) {
            if (s[i] != s[s.size()-i-1]) {
                return false;
            }
        }
        return true;
    }

    void partitionCore(const string& s, vector<string>& result, vector<vector<string>>& results) {
        if (s.empty()) { results.push_back(result); return; }

        for (int i=0; i<s.size(); ++i) {
            if (isPalindrome(s.substr(0, i+1))) {
                result.push_back(s.substr(0, i+1));
                partitionCore( s.substr(i+1), result, results );
                result.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        //回溯法
        vector<string> result;
        vector<vector<string>> results;

        partitionCore(s, result, results);
        return results;
    }
};