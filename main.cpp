#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>

using namespace std;
int lengthOfLongestSubstring(string s) {
    if (s.empty()) { return 0; }

    int hashMap[26];
    int maxLength = 0;
    int curLength = 0;
    for (int i=0; i<26; ++i)  { hashMap[i]=-1; }

    for (int i=-1, j=0; j<s.size(); ++j) {
        if (hashMap[s[j]-'a'] <= i) {
            hashMap[s[j]-'a'] = j;
            if (++curLength > maxLength) {
                maxLength = curLength;
            }
        } else {
            i = hashMap[s[j]-'a'];
            curLength = j - i;
        }
    }
    return maxLength;
}
int main() {
    vector<string> strs;
    lengthOfLongestSubstring("abcabcbcb");
    return 0;
}
