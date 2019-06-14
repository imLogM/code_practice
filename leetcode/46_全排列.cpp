//给定一个没有重复数字的序列，返回其所有可能的全排列。
//
//示例:
//
//输入: [1,2,3]
//输出:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.empty()) { return results; }

        vector<int> result;
        core(nums, 0, result, results);
        return results;
    }
    void core(vector<int>& nums, int index, vector<int>& result, vector<vector<int>>& results) {
        if (index >= nums.size()) { results.push_back(result); return; }

        for (int i=index; i<nums.size(); ++i) {
            swap(nums[i], nums[index]);
            result.push_back(nums[index]);
            core(nums, index+1, result, results);
            result.pop_back();
            swap(nums[i], nums[index]);
        }
    }
};
