//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//
//你可以假设 nums1 和 nums2 不会同时为空。
//
//示例 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
//示例 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5


class Solution {
public:
    int topK(vector<int>& nums1, int bg1, int ed1, vector<int>& nums2, int bg2, int ed2, int k) {
        int len1 = ed1-bg1;
        int len2 = ed2-bg2;

        if (k > len1 + len2 || k <= 0) {
            cout << "error k\n";
            return 0;
        }

        if (len1==0) {
            return nums2[bg2+k-1];
        }
        if (len1 > len2) {
            return topK(nums2, bg2, ed2, nums1, bg1, ed1, k);
        } else if (k==1) {
            return min(nums1[bg1], nums2[bg2]);
        }

        int mid1 = ((len1 > k/2)? k/2 : len1);
        int mid2 = (k - mid1);
        if (nums1[bg1+mid1-1] > nums2[bg2+mid2-1]) {
            return topK(nums1, bg1, ed1, nums2, bg2+mid2, ed2, k-mid2);
        } else if (nums1[bg1+mid1-1] < nums2[bg2+mid2-1]) {
            return topK(nums1, bg1+mid1, ed1, nums2, bg2, ed2, k-mid1);
        } else {
            return nums1[bg1+mid1-1];
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = (int)nums1.size();
        int len2 = (int)nums2.size();
        if (nums1.empty() && nums2.empty()) { return 0; }

        int m1 = (len1+len2+1) / 2;
        int m2 = (len1+len2+2) / 2;
        return 0.5*(topK(nums1, 0, len1, nums2, 0, len2, m1)+topK(nums1, 0, len1, nums2, 0, len2, m2));
    }
};
