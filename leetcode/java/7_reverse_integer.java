//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//Output: 321
//Example 2:
//
//Input: -123
//Output: -321
//Example 3:
//
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
// 关键点：对溢出的判断
// 时间O(logn)，空间O(1)

import java.lang.*;
import java.util.*;

class Solution {
    public int reverse(int x) {
        int result = 0;
        while (x!=0) {
            int temp = x%10;
            x = x/10;
            if (result>Integer.MAX_VALUE/10 || (result==Integer.MAX_VALUE/10 && temp>Integer.MAX_VALUE%10)) {
                return 0;
            } else if (result<Integer.MIN_VALUE/10 || (result==Integer.MIN_VALUE/10 && temp<Integer.MIN_VALUE%10)) {
                return 0;
            } else {
                result = result*10 + temp;
            }
        }
        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution so = new Solution();
        System.out.println(so.reverse(123));
        System.out.println(so.reverse(-123));
        System.out.println(so.reverse(120));
    }
}
