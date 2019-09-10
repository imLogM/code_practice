//现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。
//
//假设，您并不知道其中字母之间的先后顺序。但是，会收到词典中获得一个 不为空的 单词列表。因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。
//
//您需要根据这个输入的列表，还原出此语言中已知的字母顺序。
//
//示例 1：
//
//输入:
//[
//"wrt",
//"wrf",
//"er",
//"ett",
//"rftt"
//]
//
//输出: "wertf"
//示例 2：
//
//输入:
//[
//"z",
//"x"
//]
//
//输出: "zx"
//示例 3：
//
//输入:
//[
//"z",
//"x",
//"z"
//]
//
//输出: "" 
//
//解释: 此顺序是非法的，因此返回 ""。
//注意：
//你可以默认输入的全部都是小写字母
//假如，a 的字母排列顺序优先于 b，那么在给定的词典当中 a 定先出现在 b 前面
//若给定的顺序是不合法的，则返回空字符串即可
//若存在多种可能的合法字母顺序，请返回其中任意一种顺序即可

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 存储用到的字母
        unordered_set<char> charSet;
        for (int i=0; i<(int)words.size(); ++i) {
            for (int j=0; j<(int)words[i].size(); ++j) {
                charSet.insert(words[i][j]);
            }
        }

        vector<vector<int>> graph(26, vector<int>(26, 0));
        // 建图,同个字符串内,本题中不需要
//        for (int i=0; i<(int)words.size(); ++i) {
//            for (int j=1; j<(int)words[i].size(); ++j) {
//                if (words[i][j-1]==words[i][j]) {
//                    continue;
//                }
//                graph[words[i][j-1]-'a'][words[i][j]-'a'] = 1;
//            }
//        }

        // 建图,不同字符串间
        for (int i=1; i<(int)words.size(); ++i) {
            int j=0;
            while (j<(int)words[i-1].size() && j<(int)words[i].size()) {
                if (words[i-1][j]!=words[i][j]) {
                    graph[words[i-1][j]-'a'][words[i][j]-'a'] = 1;
                    break;
                }
                ++j;
            }
        }

        // 初始化入度表
        vector<int> inDegree(26, 0);
        for (int i=0; i<(int)graph.size(); ++i) {
            for (int j=0; j<(int)graph[i].size(); ++j) {
                if (graph[i][j] == 1) {
                    inDegree[j] += 1;
                }
            }
        }

        // 拓扑排序
        string result;
        while (!charSet.empty()) {
            bool flag = false;
            for (char ch:charSet) {
                if (inDegree[ch-'a']==0) {
                    flag = true;
                    result.push_back(ch);
                    charSet.erase(ch);
                    for (int j=0; j<(int)graph[ch-'a'].size(); ++j) {
                        if (graph[ch - 'a'][j] == 1) {
                            --inDegree[j];
                        }
                    }
                    break;
                }
            }
            if (!flag) {
                result = "";
                break;
            }
        }

        return result;
    }
};


