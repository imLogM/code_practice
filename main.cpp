#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> hashMap;
    if (strs.empty()) { return res; }

    string hashKey;
    for (string str : strs) {
        hashKey.clear();
        for (int i=0; i<26; ++i) {
            hashKey += "\1";
        }

        for (int i=0; i<str.size(); ++i) {
            hashKey[str[i]-'a'] += 1;
        }
        if (hashMap.count(hashKey)==0) {
            hashMap.insert(pair<string, int>(hashKey, res.size()));
            res.push_back(vector<string>({str}));
        } else {
            res[hashMap[hashKey]].push_back(str);
        }
    }
    return res;
}
int main() {
    vector<string> strs;
    strs.push_back("eat");
    groupAnagrams(strs);
    return 0;
}
