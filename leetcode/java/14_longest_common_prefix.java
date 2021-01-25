//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
//Note:
//
//All given inputs are in lowercase letters a-z.


// 方法：暴力求解，时间复杂度O(n)，空间复杂度O(1)

class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder ans = new StringBuilder("");
        if (strs==null || strs.length==0) {
            return ans.toString();
        }
        // 一位一位地比较
        for (int j=0; j<strs[0].length(); ++j) {
            char ch = strs[0].charAt(j);
            for (int i=0; i<strs.length; ++i) {
                if (strs[i].length()<=j || ch != strs[i].charAt(j)) {
                    return ans.toString();
                }
            }
            ans.append(ch);
        }
        return ans.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Solution slt = new Solution();
        String[] sts1 = new String[]{"flower","flow","flight"};
        System.out.println(slt.longestCommonPrefix(sts1));
        String[] sts2 = new String[]{"dog","racecar","car"};
        System.out.println(slt.longestCommonPrefix(sts2));
        String[] sts3 = new String[]{"aa","a"};
        System.out.println(slt.longestCommonPrefix(sts3));
    }
}
