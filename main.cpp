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
    string minWindow(string s, string t) {
        if (t.empty()) { return ""; }

        unordered_map<char, int> need;
        for (char ch:t) {
            if (need.find(ch)==need.end()) {
                need.insert(pair<char, int>(ch, 1));
            } else {
                ++need[ch];
            }
        }

        unordered_map<char, int> hashCount;
        for (char ch:t) {
            hashCount.insert(pair<char, int>(ch, 0));
        }

        // 滑动窗口
        int containCount = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX; string result = "";
        while (right<(int)s.size() && left <= right) {
            // 移动右指针
            while (right<(int)s.size() && containCount<(int)need.size()) {
                if (hashCount.find(s[right]) != hashCount.end()) {
                    ++hashCount[s[right]];
                    if (hashCount[s[right]] == need[s[right]]) {
                        ++containCount;
                    }
                }
                ++right;
            }
            if (containCount == (int)need.size()) {
                if (right-left < minLen) {
                    minLen = right-left;
                    result = s.substr(left, minLen);
                }
            }
            // 移动左指针
            while (left<right && containCount == (int)need.size()) {
                if (hashCount.find(s[left]) != hashCount.end()) {
                    if (right-left < minLen) {
                        minLen = right-left;
                        result = s.substr(left, minLen);
                    }
                    if (hashCount[s[left]] == need[s[left]]) {
                        --containCount;
                    }
                    --hashCount[s[left]];
                }
                ++left;
            }
        }

        return result;
    }
};


int main() {
    string s = "aa";
    string t= "aa";
    Solution sl;
    cout << sl.minWindow(s, t) << "\n";

    return 0;
}