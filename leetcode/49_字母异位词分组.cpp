//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//示例:
//
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//输出:
//[
//["ate","eat","tea"],
//["nat","tan"],
//["bat"]
//]
//说明：
//
//所有输入均为小写字母。
//不考虑答案输出的顺序。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //思路：使用hash表，每个单词计算hashKey，然后查表看有没有对应的hashKey存在
        vector<vector<string>> res;
        unordered_map<string, int> hashMap;
        if (strs.empty()) { return res; }

        string hashKey(26, '\1');     //用长26位的字符串表示hashKey，每位字符可以计数1~128
        for (string str : strs) {
            for (int i=0; i<26; ++i) {
                hashKey[i] = '\1';    //注意这边如果用'/0'的话，string类型会误认为是字符串结尾
            }

            for (int i=0; i<str.size(); ++i) {
                hashKey[str[i]-'a'] += 1;
            }
            if (hashMap.count(hashKey)==0) {
                hashMap.insert(pair<string, int>(hashKey, res.size()));
                res.push_back(vector<string>(0));
            }
            res[hashMap[hashKey]].push_back(str);
        }
        return res;
    }
};
