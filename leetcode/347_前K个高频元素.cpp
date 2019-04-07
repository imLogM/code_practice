//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//示例 1:
//
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//示例 2:
//
//输入: nums = [1], k = 1
//输出: [1]
//说明：
//
//你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

class Solution {
public:
    vector<int> toapKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k<=0 || nums.size()<k) {return res;}

        unordered_map<int, int> numsMap;
        for (int num : nums) {
            ++numsMap[num];
        }

        priority_queue<pair<int, int>> pq;
        for (auto val : numsMap) {
            pq.push(pair<int, int>(val.second, val.first));
        }
        for (int i=0; i<k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
