//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入: "A man, a plan, a canal: Panama"
//输出: true
//示例 2:
//
//输入: "race a car"
//输出: false

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()<=0) { return true; }
        //预处理：只保留数字和字母，字母全部小写
        string str1 = "";
        for (int i=0; i<s.size(); ++i) {
            if ((s[i]<='z' && s[i]>='a') || (s[i]>='0' && s[i]<='9')) {
                str1 += s[i];
            } else if (s[i]>='A' && s[i]<='Z') {
                str1 += s[i]+ ('a' -'A');
            } else {
                continue;
            }
        }
        // printf("%s\n", str1.c_str());

        int i = 0;
        int j = str1.size()-1;
        while (i<str1.size() && j>=0) {
            if (str1[i] != str1[j]) { return false; }
            ++i; --j;
        }
        return true;
    }
};