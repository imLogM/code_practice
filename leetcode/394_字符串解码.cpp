//给定一个经过编码的字符串，返回它解码后的字符串。
//
//编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
//
//示例:
//
//s = "3[a]2[bc]", 返回 "aaabcbc".
//s = "3[a2[c]]", 返回 "accaccacc".
//s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
//
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
                    tempStr = myStack.top()+tempStr;
                    myStack.pop();
                }
                myStack.pop();

                string countStr;
                while (!myStack.empty() && myStack.top()>='0' && myStack.top()<='9') {
                    countStr = myStack.top() + countStr;
                    myStack.pop();
                }
                int count = stoi(countStr);

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
