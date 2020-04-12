//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
//
//说明：
//
//分隔时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//输出:
//[
//"cats and dog",
//"cat sand dog"
//]
//示例 2：
//
//输入:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//输出:
//[
//"pine apple pen apple",
//"pineapple pen apple",
//"pine applepen apple"
//]
//解释: 注意你可以重复使用字典中的单词。
//示例 3：
//
//输入:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出:
//[]

class Solution {
public:
    vector<string> wordBreakCore(int index, const string& s, const vector<string>& wordDict,
                                 unordered_map<int, vector<string>>& memoMap) {
        vector<string> results;
        if (index==s.size()) { return results; }

        //查看以前的记忆，避免重复计算
        if (memoMap.find(index)!=memoMap.end()) {
            return memoMap[index];
        }

        for (int i=index; i<s.size(); ++i) {
            string subStr = s.substr(index, i-index+1);
            if (i<s.size()-1 &&
                find(wordDict.begin(), wordDict.end(), subStr) != wordDict.end()) {
                for ( auto subRes : wordBreakCore(i+1, s, wordDict, memoMap) ) {
                    results.push_back(subStr + " " + subRes);
                }
            } else if (i==s.size()-1 &&
                       find(wordDict.begin(), wordDict.end(), subStr) != wordDict.end()) {
                results.push_back(subStr);
            }
        }

        memoMap[index] = results;
        return results;
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> memoMap;
        if (s.empty()) { return vector<string>(); }

        return wordBreakCore(0, s, wordDict, memoMap);
    }
};