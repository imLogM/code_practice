//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//
//输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
//示例 2：
//
//输入: "cbbd"
//输出: "bb"


class Solution {
public:
    int expand(string& s, int left, int right) {
        for ( ; left>=0 && right<s.size(); ) {
            if (s[left] == s[right]) {
                --left;
                ++right;
            } else { break; }
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        //思路：依次假设每个字符为回文子串的中心，注意有两种可能的中心情况
        if (s.empty()) { return ""; }

        int maxLen = 0;
        int start, end;
        for (int i=0; i<s.size(); ++i) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            if (len1>len2 && len1>maxLen) {
                start = i - len1/2;
                end = i + len1/2;
                maxLen = len1;
            } else if (len1<len2 && len2>maxLen) {
                start = i - len2/2 + 1;
                end = i + len2/2;
                maxLen = len2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
