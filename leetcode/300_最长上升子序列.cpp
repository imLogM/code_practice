//给定一个无序的整数数组，找到其中最长上升子序列的长度。
//
//示例:
//
//输入: [10,9,2,5,3,7,101,18]
//输出: 4
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
//说明:
//
//可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
//你算法的时间复杂度应该为 O(n2) 。
//进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //使用排序后的数组与原数组做最长公共子序列
        if (nums.empty()) { return 0; }

        vector<int> numsCopy(nums);
        sort(numsCopy.begin(), numsCopy.end(), less<int>());
        //需要去重
        auto it = unique(numsCopy.begin(), numsCopy.end());
        numsCopy.erase(it, numsCopy.end());
        // for (auto num : numsCopy) {
        //     printf("%d, ", num);
        // }

        //求最长公共子序列
        vector<vector<int>> matrix(numsCopy.size()+1, vector<int>(nums.size()+1, 0));
        for (int x=1; x<numsCopy.size()+1; ++x) {
            for (int y=1; y<nums.size()+1; ++y) {
                if (nums[y-1] == numsCopy[x-1]) {
                    matrix[x][y] = matrix[x-1][y-1] + 1;
                } else {
                    matrix[x][y] = max(matrix[x-1][y], matrix[x][y-1]);
                }
            }
        }
        return matrix[numsCopy.size()][nums.size()];
    }
};