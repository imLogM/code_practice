//找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
//
//示例 1:
//
//输入:
//s = "aaabb", k = 3
//
//输出:
//3
//
//最长子串为 "aaa" ，其中 'a' 重复了 3 次。
//示例 2:
//
//输入:
//s = "ababbc", k = 2
//
//输出:
//5
//
//最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) { return 0; }

        //分治
        unordered_map<char, int> countMap;
        for (char ch : s) {
            ++countMap[ch];
        }

        int maxLen = 0;
        bool findUnmatch = false;
        for (int i=0; i<s.size(); ++i) {
            if (countMap[s[i]] < k) {
                // 一旦找到有不满足的字符，则在该字符处进行分治
                findUnmatch = true;
                maxLen = max(maxLen, longestSubstring(s.substr(0, i), k));
                // 附近的相邻的相同字符可以忽略
                int j = i;
                while (j<s.size() && s[i]==s[j]) {
                    ++j;
                }
                if (j < s.size()) {
                    maxLen = max(maxLen, longestSubstring(s.substr(j, s.size()-j), k));
                }
                break;
            }
        }
        if (!findUnmatch) {  //说明所有字符都重复k次以上
            return s.size();
        } else {
            return maxLen;
        }
    }
};
