#include <iostream>
#include <string>


int longestSubstring(const std::string& str) {
    if (str.length()<=0) { return 0; }

    int position[26];
    for (int i=0; i<26; ++i) {
        position[i] = -1;
    }
    int* longest = new int[str.length()];

    for (int i=0; i<str.length(); ++i) {
        if (position[str[i]-'a'] == -1) {
            if (i==0) { longest[i] = 1; }
            else { longest[i] = longest[i-1] + 1; }
        } else {
            if (i-position[str[i]-'a'] > longest[i-1]+1) {
                longest[i] = longest[i-1] + 1;
            } else {
                longest[i] = i-position[str[i]-'a'];
            }
        }
        position[str[i]-'a'] = i;
    }

    int max = 0;
    for (int i=0; i<str.length(); ++i) {
        if (max < longest[i]) {
            max = longest[i];
        }
    }
    delete[] longest;
    return max;
}

int main(int argc, char** argv) {
    std::string str = "abcabcacadfscfrwacsirc";
    printf("%d", longestSubstring(str));
    return 0;
}
