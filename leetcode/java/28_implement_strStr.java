//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//Output: 2
//Example 2:
//
//Input: haystack = "aaaaa", needle = "bba"
//Output: -1
//Clarification:
//
//What should we return when needle is an empty string? This is a great question to ask during an interview.
//
//For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

//方法：暴力匹配，时间复杂度O(n^2)，空间复杂度O(1)；如果对匹配窗口中的字符用特定方法哈希，则可以将时间复杂度降到O(n)
class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack==null || needle==null) { return -1; }
        else if (needle.length()==0) { return 0; }

        int pH=0;
        for (pH=0; pH<=haystack.length()-needle.length(); ++pH) {
            int j=0;
            for (int i=pH; j<needle.length(); ++i, ++j) {
                if (haystack.charAt(i) != needle.charAt(j)) {
                    break;
                }
            }
            if (j==needle.length()) { return pH; }
        }
        return -1;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution slt = new Solution();
        String hayStack="hello", needle="ll";
        System.out.println(slt.strStr(hayStack, needle));
        String hayStack2="aaaaa", needle2="bba";
        System.out.println(slt.strStr(hayStack2, needle2));
    }
}
