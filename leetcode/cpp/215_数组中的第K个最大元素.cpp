//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//示例 1:
//
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
//示例 2:
//
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4
//说明:
//
//你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。


class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        if (nums.empty() || hi <= lo) { return lo; }

        int pivot = nums[lo];
        while (hi > lo) {
            while ((hi>lo) && (nums[hi]>=pivot)) {
                --hi;
            }
            nums[lo] = nums[hi];
            while ((hi>lo) && (nums[lo]<=pivot)) {
                ++lo;
            }
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k>nums.size()) { return 0; }

        int lo = 0;
        int hi = nums.size()-1;
        while (true) {
            int mid = partition(nums, lo, hi);
            // printf("====%d\n", mid);
            // for (auto num : nums) {
            //     printf("%d, ", num);
            // }
            // printf("\n");
            if (mid == nums.size()-k) {
                return nums[mid];
            } else if (mid > nums.size()-k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
    }
};