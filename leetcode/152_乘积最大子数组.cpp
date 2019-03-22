//给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
//
//示例 1:
//
//输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
//示例 2:
//
//输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        assert(!nums.empty());

        vector<int> minNum(nums.size());
        vector<int> maxNum(nums.size());
        minNum[0] = nums[0];
        maxNum[0] = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            if (nums[i]>=0) {
                minNum[i] = min(minNum[i-1]*nums[i], nums[i]);
                maxNum[i] = max(maxNum[i-1]*nums[i], nums[i]);
            } else {
                minNum[i] = min(maxNum[i-1]*nums[i], nums[i]);
                maxNum[i] = max(minNum[i-1]*nums[i], nums[i]);
            }
        }

        return *max_element(maxNum.begin(), maxNum.end());
    }
};