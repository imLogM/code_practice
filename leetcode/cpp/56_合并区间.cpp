//给出一个区间的集合，请合并所有重叠的区间。
//
//示例 1:
//
//输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//示例 2:
//
//输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        if (intervals.empty() || intervals[0].empty()) { return results; }

        sort(intervals.begin(), intervals.end(), comp_less);
        results.push_back(intervals[0]);
        int index = 0;
        for (int i=1; i<intervals.size(); ++i) {
            if (results[index][1] >= intervals[i][0]) {
                results[index][1] = max(results[index][1], intervals[i][1]);
            } else {
                results.push_back(intervals[i]);
                ++index;
            }
        }
        return results;
    }
    static bool comp_less(const vector<int>& a, const vector<int>& b) {
        if (a[0] < b[0]) { return true; }
        else if (a[0] > b[0]) { return false; }
        else { return a[1] < b[1]; }
    }
};
