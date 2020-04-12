//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例:
//
//输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        int n = pow(2, nums.size()) - 1;
        for (int i=n; i>=0; --i) {
            subset(i, nums, results);
        }
        return results;
    }

    void subset(int n, vector<int>& nums, vector<vector<int>>& results) {
        vector<int> result;
        for (int i=0; n>0; ++i) {
            if (n & 0x1 == 1) {
                result.push_back(nums[i]);
            }
            n = (n >> 1);
        }
        results.push_back(result);
    }
};
