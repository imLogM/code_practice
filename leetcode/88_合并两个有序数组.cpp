//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明:
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例:
//
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6]



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 类似归并排序
        // 注意考虑m<=0, n<=0的情况
        vector<int> nums;
        nums.resize(m+n);

        if (n == 0) { return; }
        else if (m == 0) {
            for (int i=0; i<n; ++i) {
                nums[i] = nums2[i];
            }
            nums1 = nums;
            return;
        }

        int i = 0;
        int j = 0;
        int k = 0;
        for ( ; j<m || k<n; ) {
            if ((j<m) && ((k>=n) || (nums1[j]<=nums2[k]))) {
                nums[i] = nums1[j];
                ++i; ++j;
            }
            if ((k<n) && ((j>=m) || (nums1[j])>nums2[k])) {
                nums[i] = nums2[k];
                ++i; ++k;
            }
        }
        nums1 = nums;
    }
};