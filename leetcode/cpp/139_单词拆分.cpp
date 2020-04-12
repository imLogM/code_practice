//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//示例 2：
//
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//注意你可以重复使用字典中的单词。
//示例 3：
//
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) { return false; }

        vector<bool> dp(s.size(), false);
        string subStr;
        for (int i=0; i<s.size(); ++i) {
            subStr = s.substr(0, i+1);
            if (find(wordDict.begin(), wordDict.end(), subStr) != wordDict.end()) {
                dp[i] = true;
            } else {
                for (int j=0; j<i; ++j) {
                    if ( dp[j] ) {
                        subStr = s.substr(j+1, i-j);
                        if (find(wordDict.begin(), wordDict.end(), subStr) != wordDict.end()) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }

        bool res = dp[s.size()-1];
        return res;
    }
};