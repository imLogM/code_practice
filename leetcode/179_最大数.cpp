//给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
//
//示例 1:
//
//输入: [10,2]
//输出: 210
//示例 2:
//
//输入: [3,30,34,5,9]
//输出: 9534330
//说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。


class Solution {
public:
    static bool cmp_greater(const string& a, const string& b) {
        return (b+a)<(a+b);
    }
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) { return ""; }

        string res = "";
        vector<string> numsStr;
        for (int num : nums) {
            numsStr.push_back(to_string(num));
        }
        sort(numsStr.begin(), numsStr.end(), cmp_greater);
        if (numsStr[0] == "0") {
            return "0";
        }
        for (string str : numsStr) {
            res += str;
        }
        return res;
    }
};