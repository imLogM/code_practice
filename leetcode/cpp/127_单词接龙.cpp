//给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
//
//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典中的单词。
//说明:
//
//如果不存在这样的转换序列，返回 0。
//所有单词具有相同的长度。
//所有单词只由小写字母组成。
//字典中不存在重复的单词。
//你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
//示例 1:
//
//输入:
//beginWord = "hit",
//        endWord = "cog",
//        wordList = ["hot","dot","dog","lot","log","cog"]
//
//输出: 5
//
//解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//返回它的长度 5。
//示例 2:
//
//输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: 0
//
//解释: endWord "cog" 不在字典中，所以无法进行转换。

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.empty() || endWord.empty())  { return 0; }
        if (beginWord == endWord) { return 1; }

        unordered_set<string> dict;
        for (string word : wordList) {
            dict.insert(word);
        }

        //宽度优先遍历
        queue< pair<string, int> > q;
        q.push( pair<string, int>(beginWord, 1) );
        dict.erase(beginWord);

        while (!q.empty()) {
            string tempWord = q.front().first;
            int length = q.front().second;
            q.pop();
            for (int i=0; i<tempWord.size(); ++i) {
                string temp = tempWord;
                for (char ch='a'; ch<='z'; ++ch) {
                    temp[i] = ch;
                    if (dict.find(temp) != dict.end()) {
                        if (temp == endWord) {
                            return length + 1;
                        }
                        q.push( pair<string, int>(temp, length+1) );
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};