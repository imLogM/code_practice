#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<char> myStack;
        for (int i=0; i<(int)s.size(); ++i) {
            if (s[i]!=']') {
                myStack.push(s[i]);
            } else {
                string tempStr;
                while (myStack.top()!='[') {
                    tempStr = myStack.top() + tempStr;
                    myStack.pop();
                }
                myStack.pop();

                int count = 0;
                string countStr
                while (!myStack.empty() && myStack.top()>='0' && myStack.top()<='9') {
                    count = count*10 + myStack.top() - '0';
                    myStack.pop();
                }

                for (int j=0; j<count; ++j) {
                    for (int k=0; k<(int)tempStr.size(); ++k) {
                        myStack.push(tempStr[k]);
                    }
                }
            }
        }

        string result;
        while (!myStack.empty()) {
            result = myStack.top() + result;
            myStack.pop();
        }
        return result;
    }
};
int main()
{
    Solution so;
    cout << so.decodeString("100[leetcode]") << endl;
    return 0;
}