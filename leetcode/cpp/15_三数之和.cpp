//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//[-1, 0, 1],
//[-1, -1, 2]
//]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 思路：先固定三个数中最小的一个数的值，然后用对撞指针找另外两个值，注意输入为[0, 0, 0, 0]的情况
        vector<vector<int>> res;
        if (nums.size()<3) { return res; }

        sort(nums.begin(), nums.end(), less<int>());
        int lastNumI=INT_MAX;
        const int target = 0;
        for (int i=0; i<=nums.size()-3; ++i) {
            if (nums[i] == lastNumI) {
                continue;
            } else {
                lastNumI = nums[i];
            }
            for (int j=i+1, k=nums.size()-1; j<k; ) {
                if (nums[i]+nums[j]+nums[k]>target) {
                    --k;
                } else if (nums[i]+nums[j]+nums[k]<target) {
                    ++j;
                } else {
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    int lastNumJ = nums[j], lastNumK = nums[k];
                    while (j<=k && nums[j]==lastNumJ) {
                        ++j;
                    }
                    while (j<=k && nums[k]==lastNumK) {
                        --k;
                    }
                }
            }
        }
        return res;
    }
};
