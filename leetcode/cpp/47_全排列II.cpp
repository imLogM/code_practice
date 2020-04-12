//给定一个可包含重复数字的序列，返回所有不重复的全排列。
//
//示例:
//
//输入: [1,1,2]
//输出:
//[
//[1,1,2],
//[1,2,1],
//[2,1,1]
//]

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.empty()) { return results; }

        vector<int> result;
        core(nums, result, results, 0);
        return results;
    }
    void core(vector<int>& nums, vector<int>& result, vector<vector<int>>& results, int index) {
        if (index >= nums.size()) {
            results.push_back(result);
            return;
        }

        vector<int> tempNums = nums;
        sort(nums.begin()+index, nums.end());
        for (int i=index; i<nums.size(); ++i) {
            if(i>index && nums[i]==nums[i-1]) {
                continue;
            } else {
                swap(nums[index], nums[i]);
                result.push_back(nums[index]);
                core(nums, result, results, index+1);
                result.pop_back();
                swap(nums[index], nums[i]);
            }
        }
        nums = tempNums;
    }
};
