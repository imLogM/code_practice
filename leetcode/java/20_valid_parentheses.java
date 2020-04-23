//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//
//Example 1:
//
//Input: "()"
//Output: true
//Example 2:
//
//Input: "()[]{}"
//Output: true
//Example 3:
//
//Input: "(]"
//Output: false
//Example 4:
//
//Input: "([)]"
//Output: false
//Example 5:
//
//Input: "{[]}"
//Output: true

// 方法：栈，时间复杂度O(n)，空间复杂度O(n)
import java.util.HashMap;
import java.util.Stack;
import java.util.Map;

class Solution {
    Map<Character, Character> map = new HashMap<>();
    public Solution() {
        map.put(')', '(');
        map.put(']', '[');
        map.put('}', '{');
    }
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i=0; i<s.length(); ++i) {
            if (!map.containsKey(s.charAt(i))) {
                stack.push(s.charAt(i));
            } else if (!stack.empty() && stack.peek()==map.get(s.charAt(i))) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
}

public class Main {
    public static void main(String[] args) {
        Solution slt = new Solution();
        String s1 = "()[]{}";
        System.out.println(slt.isValid(s1));
        String s2 = "(]";
        System.out.println(slt.isValid(s2));
        String s3 = "([)]";
        System.out.println(slt.isValid(s3));
        String s4 = "{[]}";
        System.out.println(slt.isValid(s4));
        String s5 = "";
        System.out.println(slt.isValid(s5));
    }
}