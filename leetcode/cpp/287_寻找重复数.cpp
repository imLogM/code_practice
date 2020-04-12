//给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
//
//示例 1:
//
//输入: [1,3,4,2,2]
//输出: 2
//示例 2:
//
//输入: [3,1,3,4,2]
//输出: 3
//说明：
//
//不能更改原数组（假设数组是只读的）。
//只能使用额外的 O(1) 的空间。
//时间复杂度小于 O(n2) 。
//数组中只有一个重复的数字，但它可能不止重复出现一次。

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) { return -1; }
        //取mid = n/2，统计小于等于n/2的数字有几个，来判断进入比mid大的区间还是比mid小的区间继续搜寻
        int lo = 1;
        int hi = nums.size()-1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    ++count;
                }
            }
            if (count <= mid) {
                //说明重复数在比mid大的区间
                lo = mid + 1;
            } else {
                //说明重复数在mid小的区间
                hi = mid;
            }
        }
        return lo;
    }
};