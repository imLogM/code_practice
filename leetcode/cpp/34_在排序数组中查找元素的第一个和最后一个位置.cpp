//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回 [-1, -1]。
//
//示例 1:
//
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4]
//示例 2:
//
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result({-1, -1});
        if (nums.empty()) { return result; }

        result[0] = low_bound(nums, target);
        result[1] = upper_bound(nums, target);
        return result;
    }
    int low_bound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();

        while(hi>lo) {
            int mid = (lo + hi) / 2;
            if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (lo>=nums.size() || nums[lo] != target) {
            return -1;
        } else {
            return lo;
        }

    }
    int upper_bound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();

        while(hi>lo) {
            int mid = (lo + hi) / 2;
            if (target >= nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (--lo < 0 || nums[lo] != target) {
            return -1;
        } else {
            return lo;
        }

    }
};
