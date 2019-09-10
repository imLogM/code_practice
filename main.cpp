#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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
        // 建图,同个字符串内
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

int main() {
    vector<string> words;
    words.push_back("wrt");
    words.push_back("wrf");
    words.push_back("er");
    words.push_back("ett");
    words.push_back("rftt");
//    words.push_back("x");
//    words.push_back("z");
    Solution s;
    cout << s.alienOrder(words) << "\n";

    return 0;
}