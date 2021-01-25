//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//Follow up:
//
//If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//

//方法：从左到右累加和，遇到和为负数时重置，时间复杂度O(n)，空间复杂度O(n)
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length<=0) { return 0; }

        int[] sums = new int[nums.length];
        for (int i=0; i<nums.length; ++i) {
            if (i==0 || sums[i-1]<0) {
                sums[i] = nums[i];
            } else {
                sums[i] = nums[i] + sums[i-1];
            }
        }

        int ans = Integer.MIN_VALUE;
        for (int sum:sums) {
            if (ans < sum) { ans = sum; }
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution slt = new Solution();
        int[] nums = new int[]{-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(slt.maxSubArray(nums));
    }
}
