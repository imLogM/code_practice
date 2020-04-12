//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

// 使用哈希表进行检索，时间O(n)，空间O(n);
// 如果排序+双指针，时间O(nlogn)，空间O(1)
import java.lang.*;
import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<nums.length; ++i) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            } else {
                map.put(nums[i], i);
            }
        }
        throw new IllegalArgumentException("no twoSum solution");
    }
}

public class Main {
    public static void main(String[] args) {
        Solution so = new Solution();
        int[] nums = new int[]{2,11,7,5};
        int target = 9;
        int[] result = so.twoSum(nums, target);
        System.out.printf("results: %d, %d\n", result[0], result[1]);
    }
}
