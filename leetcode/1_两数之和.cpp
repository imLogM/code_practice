//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例:
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
//


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size()<=1) { return vector<int>({0,0}); }

        vector<pair<int, int>> m;
        for (int i=0; i<nums.size(); ++i) {
            m.push_back(pair<int, int>(i, nums[i]));
        }
        sort(m.begin(), m.end(), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});

        int pHead = 0, pTail = nums.size()-1;
        while (pTail > pHead) {
            if (m[pHead].second + m[pTail].second == target) {
                break;
            } else if (m[pHead].second + m[pTail].second > target) {
                --pTail;
            } else {
                ++pHead;
            }
        }

        if (m[pHead].second + m[pTail].second == target) {
            return vector<int>({m[pHead].first, m[pTail].first});
        } else {
            return vector<int>({0,0});
        }
    }
};
