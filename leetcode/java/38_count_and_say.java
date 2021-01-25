//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
// 
//
//Example 1:
//
//Input: 1
//Output: "1"
//Explanation: This is the base case.
//Example 2:
//
//Input: 4
//Output: "1211"
//Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".

//方法：递归，递归核是简单的计数，时间复杂度O(n^2)，空间复杂度O(n)
import java.util.HashMap;
import java.util.Map;
class Solution {
    private Map<Integer, String> map = new HashMap<>();
    public Solution() { map.put(1, "1"); }
    public String countAndSay(int n) {
        if (n<=0) { return "0"; }
        if (map.containsKey(n)) { return map.get(n); }
        else {
            StringBuilder ans = new StringBuilder("");
            String prevAns = countAndSay(n-1);
            int sameChNum = 1;
            for (int i=0; i<prevAns.length(); ++i) {
                if (i==prevAns.length()-1 || prevAns.charAt(i)!=prevAns.charAt(i+1)) {
                    ans.append(sameChNum).append(prevAns.charAt(i));
                    sameChNum = 1;
                } else {
                    ++sameChNum;
                }
            }
            map.put(n, ans.toString());
            return ans.toString();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Solution slt = new Solution();
        System.out.println(slt.countAndSay(0));
        System.out.println(slt.countAndSay(1));
        System.out.println(slt.countAndSay(4));
        System.out.println(slt.countAndSay(3));
        System.out.println(slt.countAndSay(5));
    }
}
