//给定一个未排序的整数数组，找出最长连续序列的长度。
//
//要求算法的时间复杂度为 O(n)。
//
//示例:
//
//输入: [100, 4, 200, 1, 3, 2]
//输出: 4
//解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //对于数组里的每个数，去查询数组中是否存在邻近的数，虽然是两层循环，但是实际复杂度O(1)

        if (nums.empty()) { return 0; }

        unordered_set<int> hash(nums.begin(), nums.end());
        int longest = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (hash.find(nums[i])==hash.end()) {
                //hash中找不到，说明该元素之前已经参与了查找邻近数
                continue;
            }
            hash.erase(nums[i]);
            //开始找邻近数
            int pre = nums[i] - 1;
            int next = nums[i] + 1;
            while (hash.find(pre) != hash.end()) {
                hash.erase(pre);
                --pre;
            }
            while (hash.find(next) != hash.end()) {
                hash.erase(next);
                ++next;
            }
            longest = max(longest, next-pre-1);
        }
        return longest;
    }
};