//示例 1:
//
//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2,2]
//示例 2:
//
//输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出: [4,9]
//说明：
//
//输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
//我们可以不考虑输出结果的顺序。
//进阶:
//
//如果给定的数组已经排好序呢？你将如何优化你的算法？
//如果 nums1 的大小比 nums2 小很多，哪种方法更优？
//如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) { return res; }

        multiset<int, less<int>> set1(nums1.begin(), nums1.end());
        multiset<int, less<int>> set2(nums2.begin(), nums2.end());

        for (auto pos1=set1.begin(); pos1!=set1.end(); ) {
            auto pos2 = set2.find(*pos1);
            if (pos2 != set2.end()) {
                res.push_back(*pos1);
                pos1 = set1.erase(pos1);    // c++11开始支持的迭代过程中安全erase
                set2.erase(pos2);
            } else {
                ++pos1;
            }
        }
        return res;
    }
};