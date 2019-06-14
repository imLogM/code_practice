//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//说明:
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

class Solution {
public:
    void core(string& digits, int index, unordered_map<char, vector<char>>& m, string result, vector<string>& results) {
        if (index >= digits.size()) { results.push_back(result); return; }

        char num = digits[index];
        for (char ch : m[num]) {
            result += ch;
            core(digits, index+1, m, result, results);
            result.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> m;
        m.insert(pair<char, vector<char>>('2', vector<char>({'a','b','c'})));
        m.insert(pair<char, vector<char>>('3', vector<char>({'d','e','f'})));
        m.insert(pair<char, vector<char>>('4', vector<char>({'g','h','i'})));
        m.insert(pair<char, vector<char>>('5', vector<char>({'j','k','l'})));
        m.insert(pair<char, vector<char>>('6', vector<char>({'m','n','o'})));
        m.insert(pair<char, vector<char>>('7', vector<char>({'p','q','r','s'})));
        m.insert(pair<char, vector<char>>('8', vector<char>({'t','u','v'})));
        m.insert(pair<char, vector<char>>('9', vector<char>({'w','x','y','z'})));

        vector<string> results;
        string result;
        if (digits.empty()) { return results; }

        core(digits, 0, m, result, results);
        return results;
    }
};
